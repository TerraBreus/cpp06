#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>

Base *generate(void) 
{
	int decider = std::rand() % 3;
	switch (decider)
	{
		case (0) : return (new A());
		case (1) : return (new B());
		default : return (new C());
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else 
		std::cout << "Unknown";
	std::cout << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast& e) {}
	std::cout << "Unknown" << std::endl;
}

int main(void)
{
	int size = 10;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Test: " << i + 1 << std::endl;
		Base *test = generate();
		identify(test);
		identify(*test);
		delete (test);
	}
}
