#include <UART/UART.hpp>
#include <array>
#include "Roomba/Roomba.hpp"


int main(int argc, char **argv) {
	UART::UARTSettings p;
	p.devicePath = "/dev/ttyUSB0";
	p.baudrate = UART::Baudrates::baud_115200;
    p.connectionMethod = UART::connectionMethod::USB;
	std::shared_ptr<UART::UART> p1 = UART::UART::Create(p);
    std::unique_ptr<Roomba::Roomba> rmb = std::make_unique<Roomba::Roomba>(p1);

    while(1) {
        rmb->setDirection(Roomba::Forward);
        SLEEP(100);
        if(rmb->getSensorData(Roomba::Wall).u8){
            rmb->setDirection(Roomba::Left);
            SLEEP(1000);
        }
    }
	return (0);
}
