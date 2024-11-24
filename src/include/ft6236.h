// Copyright (c) 2024 embeddedboys developers

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:

// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef __FT6236_H
#define __FT6236_H

#include <stdint.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#define FT6236_PIN_SCL   3
#define FT6236_PIN_SDA   2
#define FT6236_PIN_RST   22
#define FT6236_PIN_IRQ   28

#define CT_MAX_TOUCH  5

#define FT_REG_DEVICE_MODE 	    0x00    // Device mode, 0x00: Normal mode, 0x04: Test mode, 0x03: Factory mode
#define FT_REG_GEST_ID 			0x01    // Gesture ID
#define FT_REG_TD_STATUS 		0x02    // Touch point status

/* TODO: currently support 1 touch point */
#define FT_REG_TOUCH1_XH 		0x03    // Touch point 1 X high 8-bit
#define FT_REG_TOUCH1_XL 		0x04    // Touch point 1 X low 8-bit
#define FT_REG_TOUCH1_YH 		0x05    // Touch point 1 Y high 8-bit
#define FT_REG_TOUCH1_YL 		0x06    // Touch point 1 Y low 8-bit

#define FT_REG_TH_GROUP			0x80
#define FT_REG_PERIODACTIVE	    0x88

#define	FT_REG_LIB_VER_H		0xA1
#define	FT_REG_LIB_VER_L		0xA2
#define FT_REG_CHIPER           0xA3
#define FT_REG_G_MODE 			0xA4
#define FT_REG_FOCALTECH_ID     0xA8
#define FT_REG_RELEASE_CODE_ID  0xAF
#define FT_REG_STATE            0xBC

#endif