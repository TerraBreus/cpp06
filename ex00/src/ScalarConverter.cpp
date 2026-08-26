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

double findType(std::string str)
{
	if (std::regex_match(str, std::regex("[\\+-]?[0-9]+")))
	{
			//integer.
		try {
			int i = std::stoi(str);
			return (static_cast<double>(i));
			}
		catch (const std::out_of_range& e) {
            throw std::invalid_argument("Integer overflow/out of range: " + str);
        }}
	throw std::invalid_argument("Invalid argument: " + str);
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
