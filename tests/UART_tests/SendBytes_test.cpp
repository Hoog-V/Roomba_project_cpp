#include <gtest/gtest.h>
#include "UART/UART.hpp"
#include "UARTDefines.hpp"


/**
 * Tests if UART_ReadBytes function checks its parameters
 * This test in particular tests if the UART_SendBytes function throws an exception when passing a zero in to
 * the NumOfBytes parameter.
 */
TEST(UART_SendBytes, numOfBytesZero) {
    UART::UARTSettings TestSettings;
    TestSettings.baudrate = TestBaud;
    TestSettings.devicePath = TestPath;
    TestSettings.connectionMethod = TestMethod;

    std::shared_ptr<UART::UART> UartHandle = UART::UART::Create(TestSettings);

    std::vector<uint8_t> TestCommands;
    EXPECT_ANY_THROW({
        UartHandle->sendBytes(TestCommands);
    });
}