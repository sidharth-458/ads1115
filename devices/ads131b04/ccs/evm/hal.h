/**
 * \copyright Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <evm/ads131b04-q1.h>
#include <stdbool.h>
#include <stdint.h>



//****************************************************************************
//
// Insert processor specific header file(s) here
//
//****************************************************************************

#ifdef EXAMPLE_CODE
/*  --- INSERT YOUR CODE HERE --- */
#include "ti/devices/msp432e4/driverlib/driverlib.h"
#else
#include "settings.h"
#endif



//****************************************************************************
//
// BoosterPack pinout...
//
//****************************************************************************
//
//                  LEFT                                RIGHT
//               /--------\                          /--------\
//        +3.3V -|3V3  +5V|- +5V                CLK -|PG1  GND|- GND
//              -|PD2  GND|- GND       nSYNC/nRESET -|PK4  PM7|-
//              -|PP0  PB4|-                    nCS -|PK5 *PP5|-
//              -|PP1  PB5|-                  nDRDY -|PM0  PA7|-
//              -|PD4  PK0|-                        -|PM1  RST|-
//              -|PD5  PK1|-                        -|PM2  PQ2|- DIN
//         SCLK -|PQ0  PK2|-                        -|PH0  PQ3|- DOUT
//              -|PP4* PK3|-                        -|PH1 *PP3|-
//              -|PN5  PA4|-                        -|PK6  PQ1|-
//              -|PN4  PA5|-                        -|PK7  PM6|-
//               \--------/                          \--------/
//
#ifdef EXAMPLE_CODE
#else
//
// * NOTE: These pins differ from the MSP-EXP432E401Y LaunchPad!
//  MSP432E LP:  PP4, PP5, PP3
//  PAMB (REV1): PA6, PN1, PN0
//  PAMB (REV2): PH3, PN3, PN2
//
#endif



//*****************************************************************************
//
// Pin definitions (MSP432E401Y)
//
//*****************************************************************************

#define nDRDY_PORT          (GPIO_PORTM_BASE)
#define nDRDY_PIN           (GPIO_PIN_0)
#define nDRDY_INT           (INT_GPIOM)

#define nCS_PORT            (GPIO_PORTK_BASE)
#define nCS_PIN             (GPIO_PIN_5)

#define nSYNC_nRESET_PORT   (GPIO_PORTK_BASE)
#define nSYNC_nRESET_PIN    (GPIO_PIN_4)

// (OPTIONAL) External clock source
//#define CLKIN_PORT          (GPIO_PORTG_BASE)
//#define CLKIN_PIN           (GPIO_PIN_1)



//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************

void    InitADC(void);
void    delay_ms(const uint32_t delay_time_ms);
void    delay_us(const uint32_t delay_time_us);
void    setCS(const bool state);
void    setSYNC_RESET(const bool state);
void    toggleSYNC(void);
void    toggleRESET(void);
void    spiSendReceiveArrays(const uint8_t DataTx[], uint8_t DataRx[], const uint8_t byteLength);
uint8_t spiSendReceiveByte(const uint8_t dataTx);
bool    waitForDRDYinterrupt(const uint32_t timeout_ms);
#ifdef EXAMPLE_CODE
#else
bool    getDRDYinterruptStatus(void);
void    setDRDYinterruptStatus(const bool value);
void    enableDRDYinterrupt(const bool intEnable);
#endif

// Functions used for testing only
bool    getCS(void);
bool    getSYNC_RESET(void);
void    setSYNC_RESET(const bool state);



//*****************************************************************************
//
// Macros
//
//*****************************************************************************
/** Alias used for setting GPIOs pins to the logic "high" state */
#define HIGH                ((bool) true)

/** Alias used for setting GPIOs pins to the logic "low" state */
#define LOW                 ((bool) false)



#endif /* INTERFACE_H_ */
