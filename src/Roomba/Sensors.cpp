#include "Roomba/Roomba.hpp"

namespace Roomba {
    sensorData Roomba::getSensorData(sensors sensor) {
        std::vector<uint8_t> sensorCommand = { command::Sensor, sensor };
        std::vector<uint8_t> sensorDataRaw = { 0, 0 };

        mUartHandle->sendBytes(sensorCommand);
        SLEEP(1000);
        mUartHandle->readBytes(sensorDataRaw, 2);

        return sensorDataType(sensor, sensorDataRaw);
    }

    std::vector<sensorData> Roomba::getSensorDataList(std::vector<sensors> sensor) {
        std::vector<uint8_t> sensorCommand = { command::SensorList };
        std::vector<uint8_t> sensorDataRaw = { 0 };
        std::vector<sensorData> sensorDataOut;

        sensorDataRaw.reserve(sensor.size() * 2);

        sensorCommand.push_back(sensor.size());
        sensorCommand.insert(sensorCommand.end(), sensor.begin(), sensor.end());

        mUartHandle->sendBytes(sensorCommand);
        SLEEP(1000);
        mUartHandle->readBytes(sensorDataRaw, sensorDataRaw.size());

        for(size_t i = 0, byteNum = 0; i < sensor.size(); i++, byteNum++) {
            sensorDataOut.at(i) = sensorDataType(sensor.at(i), {sensorDataRaw.at(byteNum), sensorDataRaw.at(byteNum + 1)});
        }

        return sensorDataOut;
    }

    sensorData Roomba::sensorDataType(sensors sensor, std::vector<uint8_t> sensorDataRaw) {
        sensorData sensorDataOut;
        if(sensorIsSignedInt8_t(sensor)) {
            sensorDataOut.s8 = (int8_t)sensorDataRaw.at(0);
        }
        if(sensorIsUnsignedInt8_t(sensor)) {
            sensorDataOut.u8 = (uint8_t)sensorDataRaw.at(0);
        }
        if(sensorIsSignedInt16_t(sensor)) {
            sensorDataOut.s16 = (int16_t)((sensorDataRaw.at(0) << 8) | sensorDataRaw.at(1));
        }
        if(sensorIsUnsignedInt16_t(sensor)) {
            sensorDataOut.u16 = (uint16_t)((sensorDataRaw.at(0) << 8) | sensorDataRaw.at(1));
        }
        return sensorDataOut;
    }

    ///@note the numbers seen here are form the datasheet https://cdn-shop.adafruit.com/datasheets/create_2_Open_Interface_Spec.pdf seen at page 22 to 31, all these numbers are the PacketID's
    constexpr bool Roomba::sensorIsSignedInt8_t(sensors sensor) {
        return ((sensor == 24) || (sensor == 45));
    }

    constexpr bool Roomba::sensorIsUnsignedInt8_t(sensors sensor) {
        return ((sensor >= 7 && sensor <= 18) || (sensor >= 34 && sensor <= 38) || (sensor == 21) || (sensor == 52) || (sensor == 53) || (sensor == 58));
    }

    constexpr bool Roomba::sensorIsSignedInt16_t(sensors sensor) {
        return ((sensor == 19) || (sensor == 20) || (sensor == 23) || (sensor >= 29 && sensor <= 42) || (sensor >= 54 && sensor <= 57));
    }

    constexpr bool Roomba::sensorIsUnsignedInt16_t(sensors sensor) {
        return ((sensor == 22) || (sensor >= 25 && sensor <= 31) || (sensor == 43) || (sensor == 44) || (sensor >= 46 && sensor <= 51));
    }

}