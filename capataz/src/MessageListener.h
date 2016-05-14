/*
 * MessageListener.h
 *
 *  Created on: May 13, 2016
 *      Author: jose
 */

#ifndef SRC_MESSAGEPROCESSOR_MESSAGELISTENER_H_
#define SRC_MESSAGEPROCESSOR_MESSAGELISTENER_H_

#include <HuertaModuleCommunicator.h>

using namespace paletada;

namespace capataz {

class MessageListener {
public:
	MessageListener();
	virtual ~MessageListener();
	int AddModule(HuertaModuleCommunicator * module);
	int HasWaitingMessages();
	int ReadMessages(HuertaModuleCommunicator * * modules, int * messagesRead);


private:
	HuertaModuleCommunicator  * modules [];
};

} /* namespace paletada */

#endif /* SRC_MESSAGEPROCESSOR_MESSAGELISTENER_H_ */
