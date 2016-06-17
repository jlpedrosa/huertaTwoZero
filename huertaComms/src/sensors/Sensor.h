/*
 * Sensor.h
 *
 *  Created on: May 26, 2016
 *      Author: jose
 */

#ifndef SRC_SENSORS_SENSOR_H_
#define SRC_SENSORS_SENSOR_H_

#include "message/SensorReading.h"

namespace paletada {

class Sensor {
public:
	Sensor();
	virtual ~Sensor();
	virtual bool HasReading() = 0;
	virtual SensorReading * GetReading() = 0;
};

} /* namespace paletada */

#endif /* SRC_SENSORS_SENSOR_H_ */
