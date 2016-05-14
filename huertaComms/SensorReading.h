/*
 * SensorReading.h
 *
 *  Created on: May 13, 2016
 *      Author: jose
 */

#ifndef LIB_PALETADA_SRC_SENSORREADING_H_
#define LIB_PALETADA_SRC_SENSORREADING_H_

#include "Message.h"
#include <string.h>

namespace paletada {

class SensorReading: public Message {
public:
	String SensorId;
	SensorReading();
	virtual ~SensorReading();
};

} /* namespace paletada */

#endif /* LIB_PALETADA_SRC_SENSORREADING_H_ */
