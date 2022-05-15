#include <gtest/gtest.h>
#include <UART/UART.hpp>
#include "UARTDefines.hpp"

/**
 * Tests if UART_ChangeBaud function checks its parameters
 * This test in particular tests if the UART_ChangeBaud function throws an exception when passing an invalid baudrate.
 * Which in this case is a pointer to uninitialized memory location :)
 */
TEST(UART_ChangeBaud, InvalidBaudrate) {
    UART::UARTSettings TestSettings;
    TestSettings.DevicePath = TestPath;
    TestSettings.Baudrate = TestBaud;

    UART::UART *UartHandle = new UART::UART(TestSettings);

    UART::Baudrates InvalidBaud; //Create a pointer
    // const uint32_t InvalidBaud = std::rand() % 100; //Random number between 0 and 100;
    EXPECT_ANY_THROW({
        UartHandle->changeBaud(InvalidBaud);
    });
}

/**
 * Tests if UART_ChangeBaud function checks its parameters
 * This test in particular tests if the UART_ChangeBaud function throws no exception when passing a valid baudrate
 */
TEST(UART_ChangeBaud, ValidBaudrate) {
    UART::UARTSettings TestSettings;
    TestSettings.DevicePath = TestPath;
    TestSettings.Baudrate = TestBaud;

    UART::UART *UartHandle = new UART::UART(TestSettings);

    EXPECT_NO_THROW({
        UartHandle->changeBaud(UART::Baudrates::baud_9600);
    });
}