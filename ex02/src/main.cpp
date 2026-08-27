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
		std::cout << " Type A" << std::endl;
		return ;
	}
	catch (std::bad_cast& e) {}
	try 
	{
		(void)dynamic_cast<B&>(ref);
		std::cout << " Type B" << std::endl;
		return ;
	}
	catch (std::bad_cast& e) {}
	try 
	{
		(void)dynamic_cast<C&>(ref);
		std::cout << " Type C" << std::endl;
		return ;
	}
	catch (std::bad_cast& e) {}
	std::cout << "Unidentied Type" << std::endl;
}

// An unknown derived class to test unrecognized types
class Unknown : public Base {};

int main() {
    // 1. Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "=== 1. Testing Random Generation & Identification ===" << std::endl;
    for (int i = 0; i < 5; ++i) {
        Base* instance = generate();
        
        std::cout << "Test #" << i + 1 << " -> ";
        std::cout << "Pointer: ";
        identify(instance);
        
        std::cout << "          Reference: ";
        identify(*instance);
        
        delete instance;
    }
    std::cout << std::endl;

    std::cout << "=== 2. Testing Explicit Known Types ===" << std::endl;
    A a;
    B b;
    C c;

    std::cout << "Explicit A: (Ptr) ";
    identify(&a);
    std::cout << "            (Ref) ";
    identify(a);

    std::cout << "Explicit B: (Ptr) ";
    identify(&b);
    std::cout << "            (Ref) ";
    identify(b);

    std::cout << "Explicit C: (Ptr) ";
    identify(&c);
    std::cout << "            (Ref) ";
    identify(c);
    std::cout << std::endl;

    std::cout << "=== 3. Edge Case: NULL Pointer ===" << std::endl;
    Base* nullPtr = NULL;
    std::cout << "Identifying NULL pointer: ";
    identify(nullPtr);
    std::cout << std::endl;

    std::cout << "=== 4. Edge Case: Unknown Derived Class ===" << std::endl;
    Unknown unknownObj;
    std::cout << "Unknown Class: (Ptr) ";
    identify(&unknownObj);
    std::cout << "               (Ref) ";
    identify(unknownObj);
    std::cout << std::endl;

    std::cout << "=== 5. Edge Case: Raw Base Instance ===" << std::endl;
    Base pureBase;
    std::cout << "Pure Base:     (Ptr) ";
    identify(&pureBase);
    std::cout << "               (Ref) ";
    identify(pureBase);

    return 0;
}
