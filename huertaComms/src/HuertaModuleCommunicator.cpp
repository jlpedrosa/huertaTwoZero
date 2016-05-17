/*
 * HuertaModuleCommunicator.cpp
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#include "HuertaModuleCommunicator.h"

namespace paletada
{

HuertaModuleCommunicator::HuertaModuleCommunicator(Pregonador *pregonator) {
	_pregonator = pregonator;

}

HuertaModuleCommunicator::~HuertaModuleCommunicator() {
	// TODO Auto-generated destructor stub
}



int HuertaModuleCommunicator::SendMessage(Message *message)
{
		uint8_t * serializedMessage;

}

int HuertaModuleCommunicator::ReceiveMessage(Message *message)
{

}



} /* namespace paletada */
