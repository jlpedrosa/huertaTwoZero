/*
 * main.cpp
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#include <Arduino.h>
#include <SoftwareSerial.h>



HardwareSerial *pcHW;
HardwareSerial *otherHW;

Stream *pc;
Stream *other;

#define buffLen 2048
int read;
int written;

uint8_t buffer[buffLen];


void DoBridge(Stream *source, Stream *destination) {

	digitalWrite(LED_BUILTIN, HIGH);
	read = source->readBytes(buffer, buffLen);
	written = destination->write(buffer, read);
	digitalWrite(LED_BUILTIN, LOW);

	while (read != written)
	{
		digitalWrite(LED_BUILTIN, HIGH);
		delay(1000);
		digitalWrite(LED_BUILTIN, LOW);
	}
}

void setup() {

	pcHW = &Serial;
	otherHW = &Serial1;

	pcHW->begin(9600);
	otherHW->begin(9600);

	pc = pcHW;
	other = otherHW;
}


void loop() {

	int noOne = 0;

	if(other->available())
	{
		noOne++;
		DoBridge(other, pc);
	}

	if(pc->available())
	{
		noOne++;
		DoBridge(pc, other);
	}

	if (noOne)
	{
		delay(10);
	}
}
