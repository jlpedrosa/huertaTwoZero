/*
 * ErrorMessage.h
 *
 *  Created on: May 15, 2016
 *      Author: jose
 */

#ifndef ERRORMESSAGE_H_
#define ERRORMESSAGE_H_

#include "Message.h"

namespace paletada {

class ErrorMessage : public  Message {
public:
	ErrorMessage();
	virtual ~ErrorMessage();
};

} /* namespace paletada */

#endif /* ERRORMESSAGE_H_ */
