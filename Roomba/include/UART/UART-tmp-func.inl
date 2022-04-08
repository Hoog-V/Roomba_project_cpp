#pragma once

template <typename arr, std::size_t size> void UART::readBytes(std::array<arr,size> &buffer, const uint8_t numOfbytes){
		if(numOfbytes < 1 || numOfbytes > buffer.size())
			return;
		boost::system::error_code ec;
		mSerialPort->read_some(boost::asio::mutable_buffer(buffer.data(), buffer.size()), ec);
}


template <typename arr, std::size_t size> void UART::sendBytes(std::array<arr,size> &buffer, const uint8_t numOfbytes)
{
	boost::system::error_code ec;
	mSerialPort->write_some(boost::asio::mutable_buffer(buffer.data(), numOfbytes),ec);
}