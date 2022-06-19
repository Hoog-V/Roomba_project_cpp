#include <gtest/gtest.h>
#include <UART/UART.hpp>
#include "UARTDefines.hpp"




/**
 * Tests if UART_ReadBytes function checks its parameters
 * This test in particular tests if the UART_ReadBytes function throws an exception when passing a zero in to
 * the NumOfBytes parameter.
 */
TEST(UART_ReadBytes, numOfBytesZero)
{
    UART::UARTSettings TestSettings;
    TestSettings.baudrate = TestBaud;
    TestSettings.devicePath = TestPath;
    TestSettings.connectionMethod = TestMethod;

    UART::UART *UartHandle = UART::UART::Create(TestSettings);

    std::array<uint8_t, 10> TinyBuffer;
    EXPECT_ANY_THROW({
        UartHandle->readBytes(TinyBuffer.data(), 0);
    });
}
