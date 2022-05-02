//
// Created by victor on 30-4-22.
//

#include <gtest/gtest.h>
#include <UART/UART.hpp>

TEST(UART_init, EmptyDevicePath)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = "/dev/ttyS0";
    EXPECT_ANY_THROW({
        UART* u = new UART(TestSettings);
    });
}

TEST(UART_init, EmptyBaudrate)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = "";
    TestSettings.baudrate = UART::baud_115200;
    EXPECT_ANY_THROW({
        UART* u = new UART(TestSettings);
    });
}

TEST(UART_init, InvalidBaudrate)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = "/dev/ttyS0";
    TestSettings.baudrate = std::rand() % 100; //Random number between 0 and 100
    EXPECT_ANY_THROW({
        UART* u = new UART(TestSettings);
    });
    TestSettings.baudrate = UART::baud_115200;
    EXPECT_NO_THROW({
        UART* u = new UART(TestSettings);
    });
}

TEST(UART_init, ValidUartSettings)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = "/dev/ttyS0";
    TestSettings.baudrate = UART::baud_115200;
    EXPECT_NO_THROW({
        UART* u = new UART(TestSettings);
    });
}