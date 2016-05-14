/*
 * HuertaMasterModule.h
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#ifndef HUERTAMASTERMODULE_H_
#define HUERTAMASTERMODULE_H_

#include "HuertaModuleCommunicator.h"

namespace paletada {

class HuertaMasterModule: public HuertaModuleCommunicator {
public:
	int SendBeacon();
	HuertaMasterModule();
	virtual ~HuertaMasterModule();
};

} /* namespace paletada */

#endif /* HUERTAMASTERMODULE_H_ */
