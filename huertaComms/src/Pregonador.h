/*
 * Pregonador.h
 *
 *  Created on: May 17, 2016
 *      Author: jose
 */

#ifndef PREGONADOR_H_
#define PREGONADOR_H_

#include <Arduino.h>

namespace paletada {

class Pregonador {
public:
	Pregonador();
	virtual ~Pregonador();
	virtual uint8_t * sendMessage(uint8_t *  message)  = 0 ;
	virtual bool HasData() = 0;
};

} /* namespace paletada */

#endif /* PREGONADOR_H_ */
