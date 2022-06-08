#pragma once

template<typename arr, std::size_t size>
void UARTPC::readBytes(std::array<arr, size> &buffer, const uint8_t numOfBytes) {
    if (numOfBytes < 1)
        throw "Number of bytes to read is zero or negative";

    if (numOfBytes > buffer.size())
        throw "Out of bounds!";
    boost::system::error_code ec;
    mSerialPort->read_some(boost::asio::mutable_buffer(buffer.data(), buffer.size()), ec);
}


template<typename arr, std::size_t size>
void UARTPC::sendBytes(std::array<arr, size> &buffer, const uint8_t numOfBytes) {
    if (numOfBytes < 1)
        throw "Number of bytes to send is zero or negative";

    if (numOfBytes < 1 || numOfBytes > buffer.size())
        throw "Out of bounds!";
    boost::system::error_code ec;
    mSerialPort->write_some(boost::asio::mutable_buffer(buffer.data(), numOfBytes), ec);
}