#include <UART/UART.hpp>
#include <stdint.h>
#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>

UART::UART(const UARTSettings Settings)
{
		std::cout << "New instance of the UART object" << '\n';
		std::cout << "Uartsettings Path: " << Settings.DevicePath << " Baudrate: " << Settings.baudrate << '\n';
		try{
			mSerialPort = serial_port_ptr(new boost::asio::serial_port(mIOService));
			mSerialPort->open(Settings.DevicePath);
			mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(Settings.baudrate));
		}
		catch(const std::exception &exc){
			std::cerr << "Error while creating serialport" << '\n';
		}
}

UART::~UART()
{
	boost::system::error_code ec;
	std::cout << "Destructor Called\n";
	mSerialPort->close(ec);
	mIOService.stop();
	if(ec)
		std::cerr << "Closing serialport failed!" << '\n';
	else
		std::cout << "Serial port succesfully closed!" << '\n';
}

void UART::changeBaud(const uint32_t baudrate)
{
	boost::system::error_code ec;
	mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(baudrate));
	if(ec)
		std::cerr << "Changing baudrate failed!" << '\n';
	else
		std::cout << "Succesfully changed baudrate!" << '\n';
}


void UART::sendBytes(const uint8_t *bytes, const uint8_t numOfbytes){
	boost::system::error_code ec;
	mSerialPort->write_some(boost::asio::buffer(bytes, numOfbytes),ec);
}


