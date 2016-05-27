/*
 * PregoneroWifi.h
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#ifndef LIB_PREGONEROWIFI_H_
#define LIB_PREGONEROWIFI_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define MSG_BUFFER_MAX_2 2048
#define HW_RESET_RETRIES 3
#define SERVER_CONNECT_RETRIES_BEFORE_HW_RESET 3

namespace capataz {

typedef struct Flags   // 1 byte value (on a system where 8 bits is a byte
{
	bool started :1,
		 echoOnOff :1,
		 debug :1,
			serverConfigured :1, // true if a connection to a remote server is configured
			connectedToServer :1, // true if a connection to a remote server is established
			apConfigured :1, // true if the module is configured as a client station
			localApConfigured :1, localServerConfigured :1, localApRunning :1,
			localServerRunning :1, endSendWithNewline :1,
			connectToServerUsingTCP :1;
} Flags ;

class PregoneroWifi {
public:

	PregoneroWifi(Stream *serialIn,  byte resetPin, Stream *dbgSerial = NULL);
	virtual ~PregoneroWifi();

	bool setEchoMode(bool echoOnOff);

	bool begin();

	/**
	 * Set operation mode to staion.
	 *
	 * @retval true - success.
	 * @retval false - failure.
	 */
	bool setOprToStation(void);

	/**
	 * Set operation mode to softap.
	 *
	 * @retval true - success.
	 * @retval false - failure.
	 */
	bool setOprToSoftAP(void);

	/**
	 * Set operation mode to station + softap.
	 *
	 * @retval true - success.
	 * @retval false - failure.
	 */
	bool setOprToStationSoftAP(void);

	/**
	 * Changes the socket multiplexation status
	 * @retval true - success.
	 * @retval false - failure.
	 */
	bool setMUXStatus(bool enableMux);

	/**
	 * Resets the board by puting
	 * signal on reset pin;
	 */
	bool hardwareReset();

	bool joinAP(const char * bssid, const char * passwd);

private:
	Stream* _serialIn;
	Stream* _debugSerial;
	byte _resetPin;

	Flags flags;

	char msgOut[MSG_BUFFER_MAX_2];        //buffer for send method
	char msgIn[MSG_BUFFER_MAX_2]; 		//buffer for listen method = limit of incoming message..

	void writeCommand(const char* text1, const char* text2 = NULL);
	String recvString(String target1, String target2, String target3, uint32_t timeout);
	int recvString(String target, uint32_t timeout);

	byte serverRetries;
};

} /* namespace paletada */

#endif /* LIB_PREGONEROWIFI_H_ */
