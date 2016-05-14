/*
 * MessageProcessor.h
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#ifndef SRC_MESSAGEPROCESSOR_H_
#define SRC_MESSAGEPROCESSOR_H_

#include <Message.h>

namespace paletada {

class MessageProcessor {
public:
	MessageProcessor();
	virtual ~MessageProcessor();

	int ProcessMessage(Message *message);
};

} /* namespace paletada */

#endif /* SRC_MESSAGEPROCESSOR_H_ */
