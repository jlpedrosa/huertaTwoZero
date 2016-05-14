/*
 * ZagalConfig.h
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#ifndef SRC_ZAGALCONFIG_H_
#define SRC_ZAGALCONFIG_H_

#include <Arduino.h>

namespace zagal {

class ZagalConfig {
public:

	String deviceId;
	int controlChannel;
	int dataChannel;
	ZagalConfig();
	virtual ~ZagalConfig();
};

} /* namespace paletada */

#endif /* SRC_ZAGALCONFIG_H_ */
