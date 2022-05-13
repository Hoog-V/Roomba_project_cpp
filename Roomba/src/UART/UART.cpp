#include <UART/UART.hpp>
#include <stdint.h>
#include <filesystem>
#include <iostream>
#include <boost/asio.hpp>
#include <type_traits>

UART::UART(const UARTSettings Settings)
{
        const uint32_t BaudrateVal = static_cast<uint32_t>(Settings.baudrate); //Casts enum to uint32_t value

		std::cout << "New instance of the UART object" << '\n';
		std::cout << "Uartsettings Path: " << Settings.DevicePath << " Baudrate: " << BaudrateVal << '\n';



        bool InvalidBaudrate = (BaudrateVal < 300 || BaudrateVal > 115200);

        if(InvalidBaudrate)
            throw "Invalid Baudrate";

        bool emptyDevicePath = (Settings.DevicePath == "");
        if(emptyDevicePath)
            throw "Empty DevicePath!";

        try
        {
			mSerialPort = serial_port_ptr(new boost::asio::serial_port(mIOService));
			mSerialPort->open(Settings.DevicePath);
			mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(BaudrateVal));
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

void UART::changeBaud(baudrates baudrate)
{
	boost::system::error_code ec;
    uint32_t BaudrateVal = static_cast<uint32_t>(baudrate);
    bool InvalidBaudrate = (BaudrateVal < 300 || BaudrateVal > 115200);
    if(InvalidBaudrate) {
        std::cout << "Invalid baudrate!" << '\n';
        throw "Invalid Baudrate";
    }
    else {
        mSerialPort->set_option(boost::asio::serial_port_base::baud_rate(BaudrateVal));
        if (ec)
            std::cerr << "Changing baudrate failed!" << '\n';
        else
            std::cout << "Succesfully changed baudrate!" << '\n';
    }
}


void UART::sendByte(const uint8_t byte)
{
		uint8_t buff = byte;
		boost::system::error_code ec;
		mSerialPort->write_some(boost::asio::buffer(&buff, sizeof(buff)),ec);
}
