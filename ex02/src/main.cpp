#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>

Base * generate(void) {
	int decider = std::rand() % 3;
	switch (decider)
	{
		case (0): return (new A());
		case (1): return (new B());
		default:  return (new C());
	}
}

void identify(Base* ptr)
{
	std::string type;

	if (dynamic_cast<A*>(ptr))
		type = "Class A";
	else if (dynamic_cast<B*>(ptr))
		type = "Class B";
	else if (dynamic_cast<C*>(ptr))
		type = "Class C";
	else
		type = "Unknown";
	std::cout << "Pointer identified as: " + type << std::endl;
}

void identify(Base& ref)
{
	try 
	{
		(void)dynamic_cast<A&>(ref);
		std::cout << " Type A";
		return ;
	}
	catch (std::bad_cast()) {}
	try 
	{
		(void)dynamic_cast<B&>(ref);
		std::cout << " Type B" << std::endl;
		return ;
	}
	catch (std::bad_cast()) {}
	try 
	{
		(void)dynamic_cast<C&>(ref);
		std::cout << " Type C" << std::endl;
		return ;
	}
	catch (std::bad_cast()) {}
	std::cout << "Unidentied Type" << std::endl;
}

int main()
{
	A type_a;
	B type_b;
	C type_c;

	identify(&type_a);
}
