/*
 * Message.h
 *
 *  Created on: May 13, 2016
 *      Author: jose
 */

#ifndef LIB_PALETADA_SRC_MESSAGE_H_
#define LIB_PALETADA_SRC_MESSAGE_H_

#include <Arduino.h>
#include <TimeLib.h>

namespace paletada {

class Message {
public:
	String sourceId;
	Message();
	virtual ~Message();
};

} /* namespace paletada */

#endif /* LIB_PALETADA_SRC_MESSAGE_H_ */
