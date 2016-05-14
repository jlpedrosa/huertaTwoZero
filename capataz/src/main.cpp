/*
 * main.cpp
 *
 *  Created on: May 13, 2016
 *      Author: jose
 */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include "MessageListener.h"
#include <HuertaMasterModule.h>
#include <TimeLib.h>

using namespace capataz;
using namespace paletada;


MessageListener * ml;
HuertaMasterModule * selfModule;


void setup()
{
	//Connect wifi


	//Get NTP time


	//Connect RF
	ml = new MessageListener();
	selfModule = new HuertaMasterModule();

}


void loop()
{
	int result = -1;
	//inform everyone the channel we are listening on;
	if ((result = selfModule->SendBeacon()) < 0)
	{

	}

	result = -1;
	if ((result = ml -> HasWaitingMessages()) < 0)
	{

	}

	if (result > 1)
	{

		//ml->ReadMessages()
	}

}
