/*
 * PregoneroNRF24L01.cpp
 *
 *  Created on: May 28, 2016
 *      Author: jose
 */

#include "PregoneroNRF24L01.h"

namespace paletada {

/**
   * Arduino Constructor
   *
   * Creates a new instance of this driver.  Before using, you create an instance
   * and send in the unique pins that this chip is connected to.
   *
   * @param _cepin The pin attached to Chip Enable on the RF module
   * @param _cspin The pin attached to Chip Select
   */
PregoneroNRF24L01::PregoneroNRF24L01(uint8_t _cepin, uint8_t _cspin) {
	radio = new RF24(7,8);
	radio->begin();
	radio->setAutoAck(false);

	  // Get into standby mode
	radio->startListening();
	radio->stopListening();

}

PregoneroNRF24L01::~PregoneroNRF24L01() {
	// TODO Auto-generated destructor stub
}

int PregoneroNRF24L01::FindAvailableChannel() {
}

uint8_t * PregoneroNRF24L01::sendMessage(uint8_t *  message)
{

}

bool PregoneroNRF24L01::HasData()
{

}

int PregoneroNRF24L01::FindMasterChannel()
{
	uint8_t values[NUM_CHANNELS];
	// Clear measurement values
	memset(values,0,sizeof(values));

	  // Scan all channels num_reps times
	 for (int reps = 0; reps< 1000; reps++)
	 {
		  for (int i= 0; i<NUM_CHANNELS; i++)
		  {
			  // Select this channel
			  radio->setChannel(i);

			  // Listen for a little
			  radio->startListening();
			  delayMicroseconds(225);


			  // Did we get a carrier?
			  if ( radio->testCarrier() ){
				++values[i];
			  }
			  radio->stopListening();
		}
	  }

	  // Print out channel measurements, clamped to a single hex digit
	 for (int i= 0; i<NUM_CHANNELS; i++)
	 {
	    printf("%x",min(0xf,values[i]&0xf));
	    ++i;
	 }
	 Serial.println();


}

} /* namespace paletada */

