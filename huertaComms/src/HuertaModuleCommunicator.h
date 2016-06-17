/*
 * HuertaModuleCommunicator.h
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#ifndef HUERTAMODULECOMMUNICATOR_H_
#define HUERTAMODULECOMMUNICATOR_H_

#include <include/ArduinoJson.h>
#include "message/HeartBeatMessage.h"
#include "Pregonador.h"


namespace paletada {

class HuertaModuleCommunicator {
public:
	HuertaModuleCommunicator(Pregonador *pregonator);
	virtual ~HuertaModuleCommunicator();

	int SendMessage(Message *request, Message *responseMsg);
	int ReceiveMessage(Message *message);
	int HeartBeat();
	unsigned long GetDate();
	bool HasMessages();

private:
	paletada::Pregonador * _pregonator;

};

} /* namespace paletada */

#endif /* HUERTAMODULECOMMUNICATOR_H_ */
