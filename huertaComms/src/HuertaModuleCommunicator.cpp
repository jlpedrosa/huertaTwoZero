/*
 * HuertaModuleCommunicator.cpp
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#include "HuertaModuleCommunicator.h"


namespace paletada
{

HuertaModuleCommunicator::HuertaModuleCommunicator(Pregonador *pregonator)
{
	_pregonator = pregonator;

}

HuertaModuleCommunicator::~HuertaModuleCommunicator()
{
	// TODO Auto-generated destructor stub
}



int HuertaModuleCommunicator::SendMessage(Message *request, Message *responseMsg)
{
		uint8_t * serializedMessage = request->toJson();
		if (serializedMessage <= 0)
			return -1;

		uint8_t * response = _pregonator->sendMessage(serializedMessage);

		if (serializedMessage <= 0)
			return -2;

		 DynamicJsonBuffer jsonBuffer;
		 JsonObject& root = jsonBuffer.parseObject((char *)response);

}

int HuertaModuleCommunicator::ReceiveMessage(Message *message)
{

}

int paletada::HuertaModuleCommunicator::HeartBeat()
{
	int responseCode = -1;

	paletada::HeartBeatMessage hb;
	paletada::Message *response;

	if ((responseCode = this->SendMessage(&hb, response)) < 0)
	{
		return -1;
	}

}

unsigned long paletada::HuertaModuleCommunicator::GetDate()
{

}

bool paletada::HuertaModuleCommunicator::HasMessages()
{
	return _pregonator->HasData();
}

}
/* namespace paletada */
