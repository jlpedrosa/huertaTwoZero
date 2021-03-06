/*
 * main.cpp
 *
 *  Created on: May 13, 2016
 *      Author: jose
 */

#include <Arduino.h>
#include <message/Message.h>
#include <Adafruit_Sensor.h>
#include <Time.h>
#include <HuertaModuleCommunicator.h>
#include <RF24/PregoneroNRF24L01.h>
#include <sensors/Sensor.h>

#include "ZagalConfig.h"
#include "Pinout.h"

zagal::ZagalConfig * cfg;
paletada::Sensor ** sensors;
int sensorCount =0;
paletada::HuertaModuleCommunicator *comms ;

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
	int result =-1;

	cfg = new zagal::ZagalConfig();


	Serial.println("Starting NRF24L01");
	paletada::PregoneroNRF24L01 *radio = new paletada::PregoneroNRF24L01(RF24_CEPIN,RF24_CSPIN);

	//find the control channel
	Serial.println("Look for capataz channel");
	while ((result  =radio->FindMasterChannel()) < 0 )
	{
		Serial.print("Look for capataz failed, result: ");
		Serial.println(result);
		delay(1000);
	}

	comms = new paletada::HuertaModuleCommunicator(radio);

	while ((result = comms->HeartBeat()) < 0)
	{
		Serial.print("HeartBeating failed: ");
		Serial.println(result);
		delay(1000);
	}

	unsigned long pctime;

	while ((pctime = comms->GetDate()) < 0)
	{
		Serial.print("Getting date failed: ");
		Serial.println(pctime);
		delay(1000);
	}
	setTime(pctime);

	Serial.println("Zagal starting...");

}


void loop()
{

	bool somethingDone = false;

	for(int i=0; i<sensorCount; i++)
	{
		paletada::Sensor  *sensor = sensor[i];

		if (sensor->HasReading())
		{
			somethingDone = true;
			paletada::SensorReading *reading = sensor->GetReading();
			paletada::Message *reply = NULL;
			comms->SendMessage(reading, reply);
		}
	}

	while(comms->HasMessages())
	{
		somethingDone = true;
		paletada::Message *m = NULL;
		comms->ReceiveMessage(m);
	}

	if (!somethingDone)
	{
		delay(50);
	}

}

void processMessage(paletada::Message *m)
{

}
