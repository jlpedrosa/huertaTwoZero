/*
 * PregoneroNRF24L01.h
 *
 *  Created on: May 28, 2016
 *      Author: jose
 */

#ifndef LIB_PREGONERONRF24L01_H_
#define LIB_PREGONERONRF24L01_H_

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Pregonador.h>


namespace paletada {

const uint8_t NUM_CHANNELS = 126;

class PregoneroNRF24L01 : public Pregonador {
public:
	PregoneroNRF24L01(uint8_t _cepin, uint8_t _cspin) ;
	virtual ~PregoneroNRF24L01();
	int FindMasterChannel();
	int FindAvailableChannel();
	uint8_t * sendMessage(uint8_t *  message) override;
	virtual bool HasData() override;

private:
	RF24 *radio;
};

} /* namespace paletada */

#endif /* LIB_PREGONERONRF24L01_H_ */
