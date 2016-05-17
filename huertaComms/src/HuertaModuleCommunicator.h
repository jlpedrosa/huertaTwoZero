/*
 * HuertaModuleCommunicator.h
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#ifndef HUERTAMODULECOMMUNICATOR_H_
#define HUERTAMODULECOMMUNICATOR_H_

#include  "message/Message.h"

namespace paletada {

class HuertaModuleCommunicator {
public:
	HuertaModuleCommunicator(Pregonador *pregonator);
	virtual ~HuertaModuleCommunicator();

	int SendMessage(Message *message);
	int ReceiveMessage(Message *message);

private:
	Pregonador * _pregonator;
};

} /* namespace paletada */

#endif /* HUERTAMODULECOMMUNICATOR_H_ */
