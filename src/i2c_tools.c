#include <stdio.h>
#include "hardware/gpio.h"
#include "hardware/i2c.h"

#include "debug.h"

bool reserved_addr(uint8_t addr) {
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

int i2c_bus_scan(i2c_inst_t *i2c)
{
    if (!i2c)
        i2c = i2c0;

    pr_info("\nI2C Bus Scan\n");
    pr_info("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");

    for (int addr = 0; addr < (1 << 7); ++addr) {
        if (addr % 16 == 0) {
            pr_info("%02x ", addr);
        }

        // Perform a 1-byte dummy read from the probe address. If a slave
        // acknowledges this address, the function returns the number of bytes
        // transferred. If the address byte is ignored, the function returns
        // -1.

        // Skip over any reserved addresses.
        int ret;
        uint8_t rxdata;
        if (reserved_addr(addr))
            ret = -1;
        else
            ret = i2c_read_blocking(i2c, addr, &rxdata, 1, false);

        pr_info(ret < 0 ? "." : "@");
        pr_info(addr % 16 == 15 ? "\n" : "  ");
    }
    pr_info("Done.\n");
    return 0;
}