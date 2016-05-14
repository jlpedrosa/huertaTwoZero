/*
 * main.cpp
 *
 *  Created on: May 13, 2016
 *      Author: jose
 */

#include <Arduino.h>
#include <Message.h>
#include <Adafruit_BMP085_U.h>
#include <HuertaModuleCommunicator.h>
#include "ZagalConfig.h"
#include "Pinout.h"

zagal::ZagalConfig * cfg;

void ShowErrorAndHalt(const char * msg)
{
	Serial.print(msg);
	while (1==1)
	{
		delay(1000);
	}
}

void setup()
{
	paletada::Message * m = new paletada::Message();
	m->sourceId = "testModule";

	cfg = new zagal::ZagalConfig();

	//find the control channel
	paletada::HuertaModuleCommunicator *comms = new paletada::HuertaModuleCommunicator();
	int result = comms ->ScanForMasterChannel(&(cfg->controlChannel));
	if (result < 0 )
	{
		ShowErrorAndHalt("Error initializing coms with capataz, can´t continue");
	}


}


void loop()
{



}

