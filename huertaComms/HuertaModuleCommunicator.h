/*
 * HuertaModuleCommunicator.h
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#ifndef HUERTAMODULECOMMUNICATOR_H_
#define HUERTAMODULECOMMUNICATOR_H_

#include  "Message.h"

namespace paletada {

class HuertaModuleCommunicator {
public:
	int ScanForMasterChannel(int *channel);

	int SendMessage(Message *message);
	int ReceiveMessage(Message *message);
	HuertaModuleCommunicator();
	virtual ~HuertaModuleCommunicator();
};

} /* namespace paletada */

#endif /* HUERTAMODULECOMMUNICATOR_H_ */
