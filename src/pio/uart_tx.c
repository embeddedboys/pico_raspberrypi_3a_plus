/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "uart_tx.pio.h"

int pio_uart_tx_init(uint pin_tx) {
    // This is the same as the default UART baud rate on Pico
    const uint SERIAL_BAUD = 115200;

    PIO pio = pio1;
    uint sm = 0;
    uint offset = pio_add_program(pio, &uart_tx_program);
    uart_tx_program_init(pio, sm, offset, pin_tx, SERIAL_BAUD);

    // while (true) {
    //     uart_tx_program_puts(pio, sm, "Hello, world! (from PIO!)\n");
    //     sleep_ms(1000);
    // }
    return 0;
}
