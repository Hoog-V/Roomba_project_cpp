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
    TestSettings.devicePath = TestPath;
    TestSettings.baudrate = TestBaud;

    UART::UART *UartHandle = new UART::UART(TestSettings);

    UART::Baudrates InvalidBaud; //Create a pointer
    EXPECT_THROW({
        UartHandle->changeBaud(InvalidBaud);
    }, std::invalid_argument);
}

/**
 * Tests if UART_ChangeBaud function checks its parameters
 * This test in particular tests if the UART_ChangeBaud function throws no exception when passing a valid baudrate
 */
TEST(UART_ChangeBaud, ValidBaudrate) {
    UART::UARTSettings TestSettings;
    TestSettings.devicePath = TestPath;
    TestSettings.baudrate = TestBaud;

    UART::UART *UartHandle = new UART::UART(TestSettings);

    EXPECT_NO_THROW({
        UartHandle->changeBaud(UART::Baudrates::baud_9600);
    });
}