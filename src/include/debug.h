#ifndef __DEBUG_H
#define __DEBUG_H

#include <stdio.h>
#include <stdint.h>

#include "uart_tx.pio.h"

#define DEBUG 0

#if DEBUG
#define pr_debug(fmt, ...) printf(DEBUG_TAG fmt, ##__VA_ARGS__)
#define pr_debug_nt(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define pr_debug(fmt, ...)
#define pr_debug_nt(fmt, ...)
#endif

#define pr_info(fmt, ...) pio_uart_tx_printf(fmt, ##__VA_ARGS__)
#define pr_warn(fmt, ...) pio_uart_tx_printf(fmt, ##__VA_ARGS__)
#define pr_error(fmt, ...) pio_uart_tx_printf(fmt, ##__VA_ARGS__)

#endif