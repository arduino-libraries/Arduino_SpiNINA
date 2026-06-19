/*
  This file is part of the Arduino_SpiNINA library.

  Copyright (C) Arduino s.r.l. and/or its affiliated companies

  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef SPI_Drv_h
#define SPI_Drv_h

#include <inttypes.h>
#include "spi_types.h"

#define SPI_START_CMD_DELAY 10

#define NO_LAST_PARAM 0
#define LAST_PARAM 1

#define DUMMY_DATA 0xFF

namespace SpiDrv {
  void begin(bool force = false);
  void end();
  bool initialized();

  void spiDriverInit();
  void spiSlaveSelect();
  void spiSlaveDeselect();
  char spiTransfer(volatile char data);
  void waitForSlaveReady(bool const feed_watchdog = false);
  int waitSpiChar(unsigned char waitChar);
  int readAndCheckChar(char checkChar, char* readChar);
  char readChar();
  int waitResponseParams(uint8_t cmd, uint8_t numParam, tParam* params);
  int waitResponseCmd(uint8_t cmd, uint8_t numParam, uint8_t* param, uint8_t* param_len);
  int waitResponseData8(uint8_t cmd, uint8_t* param, uint8_t* param_len);
  int waitResponseData16(uint8_t cmd, uint8_t* param, uint16_t* param_len);
  int waitResponse(uint8_t cmd, uint8_t* numParamRead, uint8_t** params, uint8_t maxNumParams);
  void sendParam(const uint8_t* param, uint8_t param_len, uint8_t lastParam = NO_LAST_PARAM);
  void sendParamNoLen(const uint8_t* param, size_t param_len, uint8_t lastParam = NO_LAST_PARAM);
  void sendParamLen8(const uint8_t param_len);
  void sendParamLen16(const uint16_t param_len);
  uint8_t readParamLen8(uint8_t* param_len = NULL);
  uint16_t readParamLen16(uint16_t* param_len = NULL);
  void sendBuffer(const uint8_t* param, uint16_t param_len, uint8_t lastParam = NO_LAST_PARAM);
  void sendParam(uint16_t param, uint8_t lastParam = NO_LAST_PARAM);
  void sendCmd(uint8_t cmd, uint8_t numParam);
  int available();
};

inline void WAIT_FOR_SLAVE_SELECT() {
  if (!SpiDrv::initialized()) {
    SpiDrv::begin();
  }
  SpiDrv::waitForSlaveReady();
  SpiDrv::spiSlaveSelect();
}

#endif
