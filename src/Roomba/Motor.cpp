#include "Roomba/Roomba.hpp"

namespace Roomba{

void Roomba::setDirection(direction Direction) {
    switch (Direction) {
        case direction::Forward:
            driveCommand(velForward, rotNone);
            break;
        case direction::Left:
            driveCommand(velStop, rotLeft);
            break;
        case direction::Right:
            driveCommand(velStop, rotRight);
            break;
        case direction::Backward:
            driveCommand(velBackward, rotNone);
            break;
        default:
            throw std::invalid_argument("Invalid direction.");
    }
}

/// velocity value may be between 500 and -500
/// radius value may be between 2000 and -2000
void Roomba::driveCommand(int16_t velocity, int16_t radius) {
    std::array<uint8_t, 5> commands{command::Drive, 
                                    static_cast<uint8_t>(velocity & 0xFF),
                                    static_cast<uint8_t>(velocity >> 8),
                                    static_cast<uint8_t>(radius & 0xFF),
                                    static_cast<uint8_t>(radius >> 8)};
    this->mUartHandle->sendBytes(commands.data(), std::size(commands));
}
}