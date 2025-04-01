/*
  wifi_spi.h - Library for Arduino WiFi shield.
  Copyright (c) 2018 Arduino SA. All rights reserved.
  Copyright (c) 2011-2014 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

#include <inttypes.h>
//#include "utility/wl_definitions.h"

#define CMD_FLAG        0
#define REPLY_FLAG      1<<7
#define DATA_FLAG 		0x40

#define WIFI_SPI_ACK        1
#define WIFI_SPI_ERR        0xFF

#define TIMEOUT_CHAR    1000

//#define	MAX_SOCK_NUM		4	/**< Maximum number of socket  */
#define NO_SOCKET_AVAIL     255

#define START_CMD   0xE0
#define END_CMD     0xEE
#define ERR_CMD   	0xEF
#define CMD_POS			1		// Position of Command OpCode on SPI stream
#define PARAM_LEN_POS 	2		// Position of Param len on SPI stream


enum numParams{
    PARAM_NUMS_0,
    PARAM_NUMS_1,
    PARAM_NUMS_2,
    PARAM_NUMS_3,
    PARAM_NUMS_4,
    PARAM_NUMS_5,
    PARAM_NUMS_6,
    MAX_PARAM_NUMS
};

#define MAX_PARAMS MAX_PARAM_NUMS-1
#define PARAM_LEN_SIZE 1

typedef struct  __attribute__((__packed__))
{
	uint8_t     paramLen;
	char*	    param;
}tParam;

typedef struct  __attribute__((__packed__))
{
	uint16_t     dataLen;
	char*	     data;
}tDataParam;


typedef struct  __attribute__((__packed__))
{
	unsigned char	cmd;
	unsigned char	tcmd;
	unsigned char	nParam;
	tParam	params[MAX_PARAMS];
}tSpiMsg;

typedef struct  __attribute__((__packed__))
{
	unsigned char	cmd;
	unsigned char	tcmd;
	unsigned char	nParam;
	tDataParam		params[MAX_PARAMS];
}tSpiMsgData;


typedef struct  __attribute__((__packed__))
{
	unsigned char	cmd;
	unsigned char	tcmd;
	//unsigned char	totLen;
	unsigned char	nParam;
}tSpiHdr;

typedef struct  __attribute__((__packed__))
{
	uint8_t     paramLen;
	uint32_t	param;
}tLongParam;

typedef struct  __attribute__((__packed__))
{
	uint8_t     paramLen;
	uint16_t	param;
}tIntParam;

typedef struct  __attribute__((__packed__))
{
	uint8_t     paramLen;
	uint8_t		param;
}tByteParam;

