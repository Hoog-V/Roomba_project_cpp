#include <gtest/gtest.h>
#include <UART/UART.hpp>
#include <array>

TEST(UART_SendBytes, OutOfBoundsCheck)
{
    UARTSettings TestSettings;
    TestSettings.baudrate = UART::baud_115200;
    TestSettings.DevicePath = "/dev/ttyS0";
    UART* p = new UART(TestSettings);
    std::array <uint8_t, 10>testarr;
    testarr.fill(0);
    EXPECT_ANY_THROW({
       p->sendBytes(testarr, 20);
    });
}

TEST(UART_SendBytes, numOfBytesZero)
{
    UARTSettings TestSettings;
    TestSettings.baudrate = UART::baud_115200;
    TestSettings.DevicePath = "/dev/ttyS0";
    UART* p = new UART(TestSettings);
    std::array <uint8_t, 10>testarr;
    testarr.fill(0);
    EXPECT_ANY_THROW({
        p->sendBytes(testarr, 0);
    });
}