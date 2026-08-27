#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"
#include <string>
#include <cstdint>
#include <iostream>

int main()
{
	Data some_data;
	some_data.name = "Scooby-Doo";
	some_data.number = 42;

	Data* data_ptr = &some_data;

	uintptr_t raw_adress;
	
	std::cout << "data.name = ";
	std::cout << data_ptr->name << std::endl;

	std::cout << "data_ptr adress: ";
	std::cout << data_ptr << std::endl;

	std::cout << "Serializing data" << std::endl;
	raw_adress = Serializer::serialize(data_ptr);

	std::cout << "PRinting raw Adress (hex format)" << std::endl;
	std::cout << std::hex << raw_adress << std::endl;
	std::cout << "Printing raw adress (dec format)" << std::endl;
	std::cout << std::dec << raw_adress << std::endl;

	Data* other_data_ptr;

	other_data_ptr = Serializer::deserialize(raw_adress);

	std::cout << other_data_ptr->name << std::endl;
}
