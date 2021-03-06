/*
 * main.cpp
 *
 *  Created on: May 13, 2016
 *      Author: jose
 */

#include <Arduino.h>
#include <SPI.h>
#include <LiquidCrystal_I2C.h>

#include <include/ArduinoJson.h>
#include <RF24/PregoneroNRF24L01.h>
#include <sensors/Sensor.h>

#include "InitialSettings.h"
#include "mainESP8266.h"
#include "mainPregonero.h"


using namespace capataz;
using namespace paletada;


HardwareSerial *wifiSerial;
HardwareSerial *debugSerial;

#define LCD_ROWS 2
#define LCD_COLUMNS  16
#define WIFI_RESET_PIN 8

LiquidCrystal_I2C lcd(0x27, LCD_COLUMNS, LCD_ROWS); // set the LCD address to 0x27 for a 16 chars and 2 line display

Sensor ** sensors;



void setup() {
	//Configure debug(PC) port
	debugSerial = &Serial;
	debugSerial->begin(9600);

	//Configure wifi ESP8266 port
	wifiSerial = &Serial1;
	wifiSerial->begin(9600);


	//Configure lcd
	lcd.init();
	lcd.backlight();
	lcd.clear();

	lcd.setCursor(0, 0);
	lcd.print("Init wifi..");

	//setupESP();
	//setupPregonero(wifiSerial, debugSerial, 8);

	//Get NTP time
	//NTPClient timeClient("europe.pool.ntp.org", 3600, 60000);

	//Connect RF
	Serial.println("Starting NRF24L01");
	paletada::PregoneroNRF24L01 *radio = new paletada::PregoneroNRF24L01(RF24_CEPIN,RF24_CSPIN);


	int availableChannel = -1;
	while ((availableChannel =radio->FindAvailableChannel())<0)
	{
		Serial.print("Error looking for an avilable channel result: ");
		Serial.println(availableChannel);
		delay(1000);
	}


	paletada::HuertaModuleCommunicator *comms = new paletada::HuertaModuleCommunicator(radio);

	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Capataz running");

}

void loop()
{

}
