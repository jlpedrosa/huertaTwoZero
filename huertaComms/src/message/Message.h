/*
 * Message.h
 *
 *  Created on: May 13, 2016
 *      Author: jose
 */

#ifndef LIB_PALETADA_SRC_MESSAGE_H_
#define LIB_PALETADA_SRC_MESSAGE_H_

#include <Arduino.h>
#include <Time.h>

namespace paletada {

class Message {
public:
	String messageType;
	String sourceId;
	unsigned long unixTs;

	Message();
	virtual ~Message();
	virtual uint8_t * toJson();
};

} /* namespace paletada */

#endif /* LIB_PALETADA_SRC_MESSAGE_H_ */
