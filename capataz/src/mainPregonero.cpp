#include "mainPregonero.h"

using namespace capataz;

void setupPregonero(Stream * wifiSerial, Stream* debugSerial, int resetPin )
{
	int result =0;
		//ESP8266  * wifi = new ESP8266(*wifiSerial, 9600);
		PregoneroWifi *wifi = new PregoneroWifi(wifiSerial, resetPin, debugSerial);
		if (wifi->begin())
		{

		}


		debugSerial->print("Joining AP....");
		if ((result = wifi->joinAP(WIFI_BSSID, WIFI_PASSWSD))!=0)
		{
			debugSerial->write("Error joining wifi: ");
			debugSerial->print(result);
			while (1==1)
			{
				delay(1000);
			}
		}

}
