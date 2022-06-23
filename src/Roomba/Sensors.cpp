#include "Roomba/Roomba.hpp"

namespace Roomba {
    sensorData Roomba::getSensorData(sensors sensor) {
        std::vector<uint8_t> sensorCommand = { command::Sensor, sensor };
        std::vector<uint8_t> sensorDataRead = { 0 };
        sensorData sensorDataOut;

        mUartHandle->sendBytes(sensorCommand);
        SLEEP(1000);
        mUartHandle->readBytes(sensorDataRead);

        if(sensorIsSingedInt8_t(sensor)) {
            sensorDataOut.s8 = (int8_t)sensorDataRead[0];
        }
        if(sensorIsUnsignedInt8_t(sensor)) {
            sensorDataOut.u8 = (uint8_t)sensorDataRead[0];
        }
        if(sensorIsSingedInt16_t(sensor)) {
            sensorDataOut.s16 = (int16_t)((sensorDataRead[0] << 8) | sensorDataRead[1]);
        }
        if(sensorIsUnsingedInt16_t(sensor)) {
            sensorDataOut.u16 = (uint16_t)((sensorDataRead[0] << 8) | sensorDataRead[1]);
        }

        return sensorDataOut;
    }

    std::vector<uint8_t> Roomba::getSensorDataList(std::vector<sensors> sensor) {
        std::vector<uint8_t> sensorCommand = { command::SensorList };
        std::vector<uint8_t> sensorData = { 0 };

        sensorCommand.push_back(sensor.size());
        sensorCommand.insert(sensorCommand.end(), sensor.begin(), sensor.end());

        mUartHandle->sendBytes(sensorCommand);
        SLEEP(1000);
        mUartHandle->readBytes(sensorData);

        return sensorData;
    }

    ///@note the numbers seen here are form the datasheet https://cdn-shop.adafruit.com/datasheets/create_2_Open_Interface_Spec.pdf seen at page 22 to 31, all these numbers are the PacketID's
    bool Roomba::sensorIsSingedInt8_t(sensors sensor) {
        return ((sensor == 24) || (sensor == 45));
    }

    bool Roomba::sensorIsUnsignedInt8_t(sensors sensor) {
        return ((sensor >= 7 && sensor <= 18) || (sensor >= 34 && sensor <= 38) || (sensor == 21) || (sensor == 52) || (sensor == 53) || (sensor == 58));
    }

    bool Roomba::sensorIsSingedInt16_t(sensors sensor) {
        return ((sensor == 19) || (sensor == 20) || (sensor == 23) || (sensor >= 29 && sensor <= 42) || (sensor >= 54 && sensor <= 57));
    }

    bool Roomba::sensorIsUnsingedInt16_t(sensors sensor) {
        return ((sensor == 22) || (sensor >= 25 && sensor <= 31) || (sensor == 43) || (sensor == 44) || (sensor >= 46 && sensor <= 51));
    }

}