/*
 * MessageSerializer.h
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#ifndef MESSAGESERIALIZER_H_
#define MESSAGESERIALIZER_H_

#include <Arduino.h>
#include "Message.h"

namespace paletada {

class MessageSerializer {
public:
	MessageSerializer();
	virtual ~MessageSerializer();

	String serialize(Message *message);
};

} /* namespace paletada */

#endif /* MESSAGESERIALIZER_H_ */
