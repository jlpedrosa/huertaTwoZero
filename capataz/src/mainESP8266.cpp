
#include "mainESP8266.h"
#include "InitialSettings.h"

/* TCP server/client example, that manages client connections, checks for messages
 *  when client is connected and parses commands. Connect to the ESP8266 IP using
 * a TCP client such as telnet, eg: telnet 192.168.0.X 2121
 *
 *  ESP8266 should be AT firmware based on 1.5 SDK or later
 *
 * 2016 - J.Whittington - engineer.john-whittington.co.uk
 */

#define esp8266_reset_pin 8 // Connect this pin to CH_PD on the esp8266, not reset. (let reset be unconnected)

#define SERVER_PORT "2121"




// the last parameter sets the local echo option for the ESP8266 module..
ESP8266wifi wifi(Serial1, Serial1, esp8266_reset_pin, Serial);

void processCommand(WifiMessage msg);

uint8_t wifi_started = false;

// TCP Commands
const char RST[] PROGMEM = "RST";
const char IDN[] PROGMEM = "*IDN?";

void setupESP() {

  Serial.println("Starting wifi");
  wifi.setTransportToTCP();// this is also default
  wifi.endSendWithNewline(false); // Will end all transmissions with a newline and carrage return ie println.. default is true

  wifi_started = wifi.begin();
  if (wifi_started)
  {
	Serial.println( "Connecting to AP");
    wifi.connectToAP(WIFI_BSSID, WIFI_PASSWSD);
    Serial.println("COnnection successfull");
    Serial.print("IP: ");
    Serial.println(wifi.getIP());
    wifi.startLocalServer(SERVER_PORT);
  }
  else
  {
    while (true)
    {
    	Serial.println("Error in connection");
    	delay(1000);

    }
  }
}

void processCommand(WifiMessage msg) {
  // return buffer
  char espBuf[MSG_BUFFER_MAX];
  // scanf holders
  int set;
  char str[16];

  // Get command and setting
  sscanf(msg.message,"%15s %d",str,&set);
  /* swSerial.print(str);*/
  /* swSerial.println(set);*/

  if ( !strcmp_P(str,IDN) ) {
    wifi.send(msg.channel,"ESP8266wifi Example");
  }
  // Reset system by temp enable watchdog
  else if ( !strcmp_P(str,RST) ) {
    wifi.send(msg.channel,"SYSTEM RESET...");
    // soft reset by reseting PC
    asm volatile ("  jmp 0");
  }
  // Unknown command
  else {
    wifi.send(msg.channel,"ERR");
  }
}


void loopESP() {

	delay(100);
  static WifiConnection *connections;

  // check connections if the ESP8266 is there
  if (wifi_started)
    wifi.checkConnections(&connections);

  // check for messages if there is a connection
  for (int i = 0; i < MAX_CONNECTIONS; i++) {
    if (connections[i].connected) {
      // See if there is a message
      WifiMessage msg = wifi.getIncomingMessage();
      // Check message is there
      if (msg.hasData) {
        // process the command
        processCommand(msg);
      }
    }
  }
}

