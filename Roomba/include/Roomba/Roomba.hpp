#pragma once
#include <UART/UART.hpp>

namespace Roomba
{

#define LED_COLOR_RED 1
#define LED_COLOR_GREEN 0

enum class cleaning{
	Spot, Clean, Max
};

enum class control
{
	No_init, Passive , Safe , Full
};

enum baudrate : uint8_t
{
	b300, b600, b1200, b2400, b4800,
	b9600, b14400, b19200, b28800, b38400,
	b57600, b115200
};

enum class sensors : uint8_t
{
	Bumps_wheeldrop, Wall, Cliff_Left, Cliff_Right, VirtualWall,
	MotorOvercurrent, DirtDetector_Left, DirtDetector_Right, RCM,
	Buttons, Distance, Angle, ChargingState, Voltage, Current, Temperature,
	Charge, Capacity
};

enum leds : uint8_t
{
	DD, MAX, CLEAN, SPOT, STATUS
};

enum command : uint8_t
{
	Start=128, Baud, Control, Safe, Full, Power, Spot, Clean,
	Max_Clean, Drive, Motors, Leds, Song, Play, Query, Dock,
	Motor_PWM, Drive_Wheels, Stream=148, Query_List, Do_Stream,
	Schedule_Leds = 162, Digit_Leds_Raw, Digit_Leds_Ascii,
	Buttons, Schedule=167, Set_Date_Time, Stop=173
};

class Roomba
{
public:
	Roomba(UART *UARTHandle){
		mUARTHandle = UARTHandle;
		mCurrControlMode =  control::No_init;
	}
	void rotate(int16_t angle);
	void setMotor(uint8_t motor, uint8_t velocity);
	void startCleaning(cleaning cleaningMode);
	void setDockMode();
	void setControlMode(control ControlMode);
	void setLed(uint8_t led, uint8_t brightness, bool color_red);
	void setBaudRate(baudrate BaudRate);
	void getSensorData(uint16_t sensor);
	void setSongNum(uint8_t songnum);
	void turnOn();
	void turnOff();
	~Roomba(){
		mUARTHandle->sendByte(command::Stop);
	}
private:
	bool mSetPassiveMode();
	bool mSetSafeMode();
	bool mSetFullMode();
	UART *mUARTHandle;
	control mCurrControlMode;
	const std::array<uint32_t, 12> baud_mapping {300, 600, 1200, 2400, 4800,
								   	   	   	   9600, 14400, 19200, 28800, 38400,
											   57600, 115200};
};

}


