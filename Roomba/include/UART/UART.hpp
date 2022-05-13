#pragma once
#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>
#include <stdint.h>






enum class baudrates : uint32_t
{
    baud_300=300,
    baud_600=600,
    baud_1200=1200,
    baud_2400=2400,
    baud_4800=4800,
    baud_9600=9600,
    baud_19200=19200,
    baud_57600=57600,
    baud_115200=115200
};

struct UARTSettings
{
    baudrates baudrate = baudrates::baud_115200;
    std::string DevicePath;
};

class UART
{
public:
    UART(const UARTSettings Settings);
	void changeBaud(baudrates baudrate);
	void sendByte(const uint8_t byte);
	template <typename arr, std::size_t size> void sendBytes(std::array<arr,size> &buffer, const uint8_t numOfbytes);
	template <typename arr, std::size_t size> void readBytes(std::array<arr,size> &buffer, const uint8_t numOfbytes);
	~UART();
private:
	typedef boost::shared_ptr<boost::asio::serial_port> serial_port_ptr;
	serial_port_ptr mSerialPort;
	boost::asio::io_service mIOService;
};



#include <UART/UART-tmp-func.inl>

