/*
 * Common.h
 *
 *  Created on: Feb 21, 2015
 *      Author: hxr5656
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <string>

#define MAXMSGSIZE 4096

#define MSG_STARTSIM 1

struct MsgStruct
{
	int messageType;
	int threadNumber;

	MsgStruct()
	{
		messageType = 0;
		threadNumber = 0;
	}
};

#endif /* COMMON_H_ */
