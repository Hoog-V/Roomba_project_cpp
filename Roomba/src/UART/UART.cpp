#include <UART/UART.hpp>
#include <stdint.h>
#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>

UART::UART(const UARTSettings Settings)
{

        bool DevicePathEmpty = Settings.DevicePath.compare("") == 0;
        if(DevicePathEmpty)
        {
            std::cerr << "DevicePath is empty!" << '\n';
            throw "DevicePath is empty!";
        }
        bool BaudrateEmpty = Settings.baudrate == 0;
        if(BaudrateEmpty)
        {
            std::cerr << "Baudrate is empty!" << '\n';
            throw "Baudrate is empty";
        }
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


void UART::sendByte(const uint8_t byte)
{
		uint8_t buff = byte;
		boost::system::error_code ec;
		mSerialPort->write_some(boost::asio::buffer(&buff, sizeof(buff)),ec);
}
