/*
 * mainESP8266.h
 *
 *  Created on: May 17, 2016
 *      Author: jose
 */

#ifndef SRC_MAINESP8266_H_
#define SRC_MAINESP8266_H_

#include <SoftwareSerial.h>
#include <ESP8266wifi.h>

void setupESP();
void loopESP();
void processCommandESP(WifiMessage msg);


#endif /* SRC_MAINESP8266_H_ */
