/*
 * HeartBeat.h
 *
 *  Created on: May 28, 2016
 *      Author: jose
 */

#ifndef SRC_MESSAGE_HEARTBEAT_H_
#define SRC_MESSAGE_HEARTBEAT_H_

#include  "Message.h"

namespace paletada {

class HeartBeat : public Message {
public:
	HeartBeat();
	virtual ~HeartBeat();
};

} /* namespace paletada */

#endif /* SRC_MESSAGE_HEARTBEAT_H_ */
