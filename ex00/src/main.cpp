#include "../inc/ScalarConverter.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::cerr << "No argument given!" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
}

