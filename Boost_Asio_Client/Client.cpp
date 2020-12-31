//
// daytime_server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


//stream style
// https://www.boost.org/doc/libs/1_68_0/doc/html/boost_asio/overview/networking/iostreams.html

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
	// 서버의 주소를 입력받고 있음 (127.0.0.1)
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: client<host>" << std::endl;
			return 1;
		}

		tcp::iostream stream(argv[1], std::to_string(int(13))); // port number : 13
		if (!stream)
		{
			std::cout << "Unable to connect: " << stream.error().message() << std::endl;
		}

		// send message to server
		stream << "Hello from client";
		stream << std::endl;

		// receive message from server
		std::string line;
		std::getline(stream, line);
		std::cout << line << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}