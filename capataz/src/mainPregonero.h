/*
 * mainPregonero.h
 *
 *  Created on: May 17, 2016
 *      Author: jose
 */

#ifndef SRC_MAINPREGONERO_H_
#define SRC_MAINPREGONERO_H_

#include <Arduino.h>
#include <PregoneroWifi.h>

#include "InitialSettings.h"

void setupPregonero(Stream * wifiSerial, Stream* debugSerial, int resetPin );


#endif /* SRC_MAINPREGONERO_H_ */
