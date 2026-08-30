#include "../inc/ScalarConverter.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
#include <regex>
#include <limits>

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
	double d;
	try {
		//RegEx; Singular +/- is optional (?), then at least one (+) [0-9] 
		if (std::regex_match(str, std::regex("[\\+-]?[0-9]+")))
		{
			//integer.
			int i = std::stoi(str);
			d = static_cast<double>(i);
		}
		else if (std::regex_match(str, std::regex("[\\+-]?[0-9]+\\.[0-9]+")))
		{
			//Double literal (4.2, -4.2, 34.123)
			d = std::stod(str);
		}
		else if (std::regex_match(str, std::regex("[\\+-]?[0-9]+\\.[0-9]+f")))
		{
			//float 4.0f, 12.456f
			float f = std::stof(str);
			d = static_cast<double>(f);
		}
		// Characters must be of length 1.
		else if (str.length() == 1)
		{
			char c = str[0];
			if (c >= '!' && c <= 'z')
				d = static_cast<double>(c);
			else
				throw std::invalid_argument("Non displayable character given.");
		}
		// Pseudo literals... you know for FUN!!! (F*cking Useful No?)
		else if (std::regex_match(str, std::regex("([\\+-]inf)|(nan)")))
		{
			d = std::stod(str);
		}
		else if (std::regex_match(str, std::regex("([\\+-]inff)|nanf")))
		{
			float f = std::stof(str);
			d = static_cast<double>(f);
		}
		else 
			throw std::invalid_argument("Argument \"" + str 
					+ "\" is neither of type; int, float, double or char! ");
	}
	catch (const std::out_of_range& e) {
		throw std::invalid_argument("Integer overflow/out of range: " + str);
	}
	catch (std::invalid_argument& e) {
		throw ;
	}
	return (d);
}
			
void printType(double d)
{
	std::cout << "Double: " << d << std::endl;
	if (d >= '!' && d <= 'z')
		std::cout << "Char: " << static_cast<char>(d) << std::endl;
	else 
		std::cout << "Char: Non displayable." << std::endl;
	if (d <= std::numeric_limits<float>::max() && d >= std::numeric_limits<float>::min())
		std::cout << "Float: " << static_cast<float>(d) << std::endl;
	else
		std::cout << "Float: Impossible" << std::endl;
	if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
		std::cout << "Int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "Int: Impossible" << std::endl;
}

ScalarConverter::~ScalarConverter(void) {
}

void ScalarConverter::convert(std::string to_convert) {
	double d;

	try
	{
		d = findType(to_convert);
		printType(d);
	}
	catch (std::invalid_argument &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
