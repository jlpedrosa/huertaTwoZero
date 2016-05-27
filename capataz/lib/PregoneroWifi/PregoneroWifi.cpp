/*
 * PregoneroWifi.cpp
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#include "PregoneroWifi.h"
const size_t buffSize = 2048;
const char CR = 13;
const char LF = 10;

const char * OK  = "OK";
const char * FAIL  = "FAIL";
const char * ERROR  = "ERROR";
const char * NO_CHANGE  = "no change";

const char * EOL  = "\n";
const char * ATE0  = "ATE0";
const char * ATE1  = "ATE1";

const char * NO_IP  = "0.0.0.0";
const char * READY  = "ready";



/**
 * Command to change the multiplexing settings for the sockets
 * TCP/UDP Connections
 *		AT+ CIPMUX?    Query
 *      AT+ CIPMUX=0	Single
 *      AT+ CIPMUX=1    Multiple
 */
const char * CIPMUX = "AT+CIPMUX=";

/**
 * Command to join an acess point
 */
const char * CWJA  = "AT+CWJAP=";

namespace capataz {

PregoneroWifi::PregoneroWifi(Stream *serialIn,  byte resetPin, Stream *dbgSerial)
{
	serverRetries = 0;

    _serialIn = serialIn;
    _resetPin = resetPin;
    _debugSerial = dbgSerial;

    pinMode(_resetPin, OUTPUT);
    digitalWrite(_resetPin, LOW);//Start with radio off

    flags.connectToServerUsingTCP = true;
    flags.endSendWithNewline = true;
    flags.started = false;
    flags.localServerConfigured = false;
    flags.localApConfigured = false;
    flags.apConfigured = false;
    flags.serverConfigured = false;

    flags.debug = false;
    flags.echoOnOff = false;

   // for (int i = 0; i < MAX_CONNECTIONS; i++) {
   //   _connections[i].channel = i + 0x30; // index to ASCII
   //   _connections[i].connected = false;
   // }

}

PregoneroWifi::~PregoneroWifi() {
	// TODO Auto-generated destructor stub
}

bool PregoneroWifi::setEchoMode(bool echoOnOff) {

	 	if(echoOnOff)//if echo = true
	        writeCommand(ATE1);
	    else
	        writeCommand(ATE0);

	 	return true;
}

bool PregoneroWifi::begin() {

    msgOut[0] = '\0';
    msgIn[0] = '\0';
    flags.connectedToServer = false;
    flags.localServerConfigured = false;
    flags.localApConfigured = false;

    serverRetries = 0;

    //Do a HW reset
    bool statusOk = false;
    byte i = 0;
    while((i<HW_RESET_RETRIES) & (!statusOk))
    {
    	if (hardwareReset())
    		statusOk = true;

    	i++;
    }

    if (!statusOk)
        return false;

    //Turn local AP = off
    if (!setOprToStation())
           return false;


    if(!setEchoMode(flags.echoOnOff))
    	 return false;


    // Set mux to enable multiple connections
    if (!setMUXStatus(true))
    	return false;

    flags.started = true;

    return true;
}

bool PregoneroWifi::hardwareReset()
{
	_debugSerial->println("Resetting ESP8266");
	digitalWrite(_resetPin, LOW);
	delay(500);
	digitalWrite(_resetPin, HIGH); //select the radio
	_debugSerial->println("Waiting for ready");
	return recvString(READY, 10000);
}


bool PregoneroWifi::setMUXStatus(bool enableMux)
{
	String command;
	command.concat(CIPMUX);
	command.concat(enableMux);

	writeCommand(command.c_str(), OK);
   // return sATCIPMUX(enableMux);
	return (false);

}

//bool PregoneroWifi::sATCIPMUX(uint8_t mode)
//{
//    String data;
//    char value ='0' + mode;
//
//    const char * mode = &value;
//
//    writeCommand(CIPMUX, mode);
//
//    data = recvString("OK", "Link is builded");
//    if (data.indexOf("OK") != -1) {
//        return true;
//    }
//    return false;
//}

bool PregoneroWifi::joinAP(const char * bssid, const char * passwd)
{
	return false;
}


void PregoneroWifi::writeCommand(const char* text1, const char* text2)
{
    this->_serialIn->write(text1);
}

int PregoneroWifi::recvString(String target, uint32_t timeout)
{
	String responseLine ;


	char buffer[2048];
    buffer[0] = '\0';

    unsigned long start = millis();
    while (millis() - start < timeout)
    {
    	responseLine = _serialIn->readStringUntil('\n');

    	int len = responseLine.length() ;
    	if (len> 0)
    	{
    		sprintf(buffer, "Received (%d) : %s",len , responseLine.c_str());
    		_debugSerial->println(buffer);

    		 if (responseLine.indexOf(target) != -1)
    		 {
    		     return 0;
    		 }
    	}

    }
    return -5;
}


String PregoneroWifi::recvString(String target1, String target2, String target3, uint32_t timeout)
{
    String data;
    char a;
    unsigned long start = millis();
    while (millis() - start < timeout)
    {
        while(_serialIn->available() > 0)
        {
            a = _serialIn->read();
			if(a == '\0') continue;
            data += a;
        }
        if (data.indexOf(target1) != -1)
        {
            break;
        }
        else if (data.indexOf(target2) != -1)
        {
            break;
        }
        else if (data.indexOf(target3) != -1) {
            break;
        }
    }
    return data;
}

bool PregoneroWifi::setOprToStation(void)
{
//    uint8_t mode;
//    if (!qATCWMODE(&mode)) {
//        return false;
//    }
//    if (mode == 1) {
//        return true;
//    } else {
//        if (sATCWMODE(1) && restart()) {
//            return true;
//        } else {
//            return false;
//        }
//    }
	return false;
}

bool PregoneroWifi::setOprToSoftAP(void)
{
	/*
    uint8_t mode;
    if (!qATCWMODE(&mode)) {
        return false;
    }
    if (mode == 2) {
        return true;
    } else {
        if (sATCWMODE(2) && restart()) {
            return true;
        } else {
            return false;
        }
    }
    */
	return false;
}

bool PregoneroWifi::setOprToStationSoftAP(void)
{
	/*
    uint8_t mode;
    if (!qATCWMODE(&mode)) {
        return false;
    }
    if (mode == 3) {
        return true;
    } else {
        if (sATCWMODE(3) && restart()) {
            return true;
        } else {
            return false;
        }
    }
    */
	return false;
}

} /* namespace capataz */
