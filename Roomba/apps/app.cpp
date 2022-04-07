#include <iostream>
#include <UART/UART.hpp>
#include <unistd.h>
#include <thread>
#include <algorithm>
#include <array>

#if defined(__linux__) || defined(__APPLE__) || defined(__WIN32)
#include <chrono>
#define SLEEP(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));
#elif defined(ESP32)
#define SLEEP(ms) vTaskDelay(ms/portTICK_PERIOD_MS);
#endif

template <typename T, std::size_t size>
constexpr int16_t convert_to_signed_short(const std::array<T, size> &buf)
{
#if(defined(LITTLE_ENDIAN) || !defined(BIG_ENDIAN))
 return ((static_cast<uint16_t>(buf.at(0)) << 8) |
           (static_cast<uint16_t>(buf.at(1))));

#elif (defined(BIG_ENDIAN))

 return ((static_cast<uint16_t>(unsigned short)buf[0]) |
           ((static_cast<uint16_t>(unsigned short)buf[1]) << 8);
# else
#error *** You have an Unsupported compiler or mixed-endian system set as compilation target ->
 	 	   This library requires either an little or big-endian target***
#endif
}

int main(int argc, char **argv)
{
	UARTSettings p;
	p.DevicePath = "/dev/ttyUSB0";
	p.baudrate = UART::baud_115200;
	UART * p1 = new UART(p);
	uint8_t k = 128;
	p1->sendBytes(&k, 1);
	SLEEP(25);
	k=130;
	p1->sendBytes(&k,1);
	SLEEP(25);
	k=131;
	p1->sendBytes(&k, 1);
	SLEEP(25);
	uint8_t bytes[] = {142,2};
	p1->sendBytes(bytes, std::size(bytes));
	uint8_t cmd[] = {137,0x00,0xC8,0x80,0x00};
	p1->sendBytes(cmd,std::size(cmd));
	std::array<uint8_t,6> buffer;
	while(true){
	SLEEP(100);
	p1->sendBytes(bytes, std::size(bytes));
	p1->readBytes(buffer, 6);
	std::array <uint8_t,2>distance {buffer.at(2),buffer.at(3)};
	std::array <uint8_t,2>Angle {buffer.at(4),buffer.at(5)};
	printf("RCM: %d, Buttons: %d, Distance: %d, Angle: %d \r\n",buffer.at(0), buffer.at(1), convert_to_signed_short(distance), convert_to_signed_short(Angle) );
	}
	delete p1;
	return (0);
}
