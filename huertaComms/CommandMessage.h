/*
 * CommandMessage.h
 *
 *  Created on: May 13, 2016
 *      Author: jose
 */

#ifndef LIB_PALETADA_SRC_COMMANDMESSAGE_H_
#define LIB_PALETADA_SRC_COMMANDMESSAGE_H_

#include "Message.h"
#include <string.h>

namespace paletada {

class CommandMessage :public  Message {
public:
	 String command;

	CommandMessage();
	virtual ~CommandMessage();
};

} /* namespace paletada */

#endif /* LIB_PALETADA_SRC_COMMANDMESSAGE_H_ */
