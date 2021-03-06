@page 5 Class Diagram
@tableofcontents

@startuml

class Roomba 
enum CleaningModes <<enumeration class>>
enum LEDS <<enumeration>>
enum Motors <<enumeration>>
enum Control <<enumeration class>>
enum Sensors <<enumeration class>>


abstract class UART <<abstract class>>
class UARTESP <<class>>
class UARTPC <<class>>

abstract class IO <<abstract class>>

enum Baudrates <<enumeration class>>

Roomba <-left- CleaningModes : 1
Roomba <-up- LEDS
Roomba <-up- Motors 
Roomba <-left- Control : 1
Roomba <-right- Sensors
Roomba <-down- UART : 1
Roomba <-left- Baudrates : 1

UART <-down- UARTPC :1
UART <-down- UARTESP:1

UART <-left- Baudrates : 1

Roomba <-down- IO : 1
IO <-down- IOPC : 1
IO <-down- IOESP :1




class Roomba {
  - mCommunicationSettings : struct
  - mIOHandle : IO
  - mUARTHandle : UART
  - mCurrControlMode : Control
  - mSetPassiveMode : bool
  - mSetSafeMode : bool
  - mSetFullMode : bool
  --
  + Roomba(mCommunicationSettings : struct) : void
  + ~Roomba() : void
  + Rotate(angle : int) : void
  + setMotor(motor : int, velocity : int) : void
  + startCleaning(cleaningMode : cleaningModes) : void
  + setDockMode() : void
  + setControlMode(controlmode : Control) : void
  + setLed( led : int, brightness : int) : void
  + setBaudrate(baudrate : baudrates) : void
  + getSensorData( sensor : int) : int
  + setSongNum(songnum : int) : void
  + turnOn() : void
  + turnOff() : void
}

enum LEDS {
DD
MAX
CLEAN
SPOT
STATUS
}

enum Motors {
Main_Brush
Vacuum
Side_Brush
}

enum Baudrates {
baud_invalid = 0
baud_300
baud_600
baud_1200
baud_2400
baud_4800
baud_9600
baud_14400
baud_19200
baud_28800
baud_38400
baud_57600
baud_115200
}

enum CleaningModes {
Normal
Full
Spot
}

enum Control {
Passive
Safe
Full
}

enum Sensors {
Bumps_wheeldrop
Wall
Cliff_Left
Cliff_Right
VirtualWall
MotorOvercurrent
DirtDetector_Left
DirtDetector_Right
RCM
Buttons
Distance
Angle
ChargingState
Voltage
Current
Temperature
Charge
Capacity
}


abstract class IO {
- mCommunicationSettings : struct
--
~ IO(mCommunicationSettings : struct) : virtual void
~ ~IO() : virtual void
~ SetPinHigh() : virtual void
~ SetPinLow() : virtual void
+ Create(mCommunicationSettings : struct) : void
}

class IOPC {
--
+ IO(mCommunicationSettings : struct) : void
+ ~IO() : void
+ SetPinHigh() : void
+ SetPinLow() : void
}

class IOESP{
--
+ IO(mCommunicationSettings : struct) : void
+ ~IO() : void
+ SetPinHigh() : void
+ SetPinLow() : void
}


abstract class UART{
- mCommunicationSettings : struct
--
~ UART(mCommunicationSettings : struct)) : virtual void
~ ~UART() : virtual void
~ changeBaud(baudrate : enum) : virtual void
~ sendBytes(buffer[] : uint8_t, numOfbytes : int) : virtual void
~ sendByte(byte : uint8_t) : virtual void
~ readBytes(buffer[] : uint8_t, numOfbytes : int) : virtual void
+ Create(mUARTsettings : struct) : void
}

class UARTPC {
- mSerialPort : boost::asio::serial_port
--
+ UART(mCommunicationSettings : struct)
+ ~UART() : void
+ changeBaud(baudrate : enum) : void
+ sendBytes(buffer[] : uint8_t, numOfbytes : uint8_t) : void
+ sendByte(byte : uint8_t) : void
+ readBytes(buffer[] : uint8_t, numOfbytes : uint8_t) : void
}

class UARTESP {
- mSerialPort : int
--
+ UART(mCommunicationSettings : struct)
+ ~UART() : void
+ changeBaud(baudrate : enum) : void
+ sendBytes(buffer[] : uint8_t, numOfbytes : int) : void
+ sendByte(byte : uint8_t) : void
+ readBytes(buffer[] : uint8_t, numOfbytes : int) : void
}

@enduml
