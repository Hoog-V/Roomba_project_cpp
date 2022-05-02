//
// Created by victor on 30-4-22.
//

#include <gtest/gtest.h>
#include <UART/UART.hpp>


TEST(UART_ChangeBaud, InvalidBaudrate)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = "/dev/ttyS0";
    TestSettings.baudrate = UART::baud_115200;
    UART *u = new UART(TestSettings);
    const uint32_t InvalidBaud = 100;
    EXPECT_ANY_THROW({
        u->changeBaud(InvalidBaud);
    });
}

TEST(UART_ChangeBaud, ValidBaudrate)
{
    UARTSettings p;
    p.DevicePath = "/dev/ttyS0";
    p.baudrate = UART::baud_115200;
    UART *u = new UART(p);
    EXPECT_NO_THROW({
        u->changeBaud(UART::baud_9600);
    });
}