#include <gtest/gtest.h>
#include <UART/UART.hpp>
#include "UARTDefines.hpp"

/**
 * Tests if UART_ChangeBaud function checks its parameters
 * This test in particular tests if the UART_ChangeBaud function throws an exception when passing an invalid baudrate
 */
TEST(UART_ChangeBaud, InvalidBaudrate)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = TestPath;
    TestSettings.baudrate = TestBaud;

    UART *UartHandle = new UART(TestSettings);

    const uint32_t InvalidBaud = std::rand() % 100; //Random number between 0 and 100;
    EXPECT_ANY_THROW({
        UartHandle->changeBaud(InvalidBaud);
    });
}

/**
 * Tests if UART_ChangeBaud function checks its parameters
 * This test in particular tests if the UART_ChangeBaud function throws no exception when passing a valid baudrate
 */
TEST(UART_ChangeBaud, ValidBaudrate)
{
    UARTSettings TestSettings;
    TestSettings.DevicePath = TestPath;
    TestSettings.baudrate = TestBaud;

    UART *UartHandle = new UART(TestSettings);

    EXPECT_NO_THROW({
        UartHandle->changeBaud(UART::baudrates::baud_9600);
    });
}