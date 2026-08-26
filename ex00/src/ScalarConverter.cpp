#include "../inc/ScalarConverter.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
#include <regex>
ScalarConverter::ScalarConverter(void) {
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {
		
	}
	return *this;
}

			

ScalarConverter::~ScalarConverter(void) {
}

void ScalarConverter::convert(std::string to_convert) {
	double d;

	try
	{
		d = findType(to_convert);
		std::cout << d << std::endl;
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
