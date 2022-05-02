#include <gtest/gtest.h>
#include <UART/UART.hpp>



TEST(UART_ReadBytes, OutOfBoundsCheck)
{
    UARTSettings TestSettings;
    TestSettings.baudrate = UART::baud_115200;
    TestSettings.DevicePath = "/dev/ttyS0";
    UART* p = new UART(TestSettings);
    std::array <uint8_t, 10>testarr;
    const uint8_t OutOfBoundsVal = 2*testarr.size();
    EXPECT_ANY_THROW({
        p->readBytes(testarr, OutOfBoundsVal);
    });
}

TEST(UART_ReadBytes, numOfBytesZero)
{
    UARTSettings TestSettings;
    TestSettings.baudrate = UART::baud_115200;
    TestSettings.DevicePath = "/dev/ttyS0";
    UART* p = new UART(TestSettings);
    std::array <uint8_t, 10>testarr;
    EXPECT_ANY_THROW({
        p->readBytes(testarr, 0);
    });
}
