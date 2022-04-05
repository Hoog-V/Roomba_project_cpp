#pragma once
#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>
#include <stdint.h>

struct UARTSettings
{
	uint32_t baudrate;
	std::filesystem::path DevicePath;
};

class UART
{
public:
	UART(const UARTSettings Settings);
	void changeBaud(const uint32_t baudrate);
	void sendBytes(const uint8_t *bytes, const uint8_t numOfbytes);
	void readBytes(const uint8_t *buffer, const uint8_t numOfbytes);
	~UART();
	enum baudrates : uint32_t
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
private:
	typedef boost::shared_ptr<boost::asio::serial_port> serial_port_ptr;
	serial_port_ptr mSerialPort;
	boost::asio::io_service mIOService;
};


