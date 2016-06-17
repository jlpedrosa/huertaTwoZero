/*
 * HeartBeat.h
 *
 *  Created on: May 28, 2016
 *      Author: jose
 */

#ifndef SRC_MESSAGE_HEARTBEATMESSAGE_H_
#define SRC_MESSAGE_HEARTBEATMESSAGE_H_

#include  "Message.h"

namespace paletada {

class HeartBeatMessage : public Message {
public:
	HeartBeatMessage();
	virtual ~HeartBeatMessage();
};

} /* namespace paletada */

#endif /* SRC_MESSAGE_HEARTBEATMESSAGE_H_ */
