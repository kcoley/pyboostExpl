#include "helloWorld.h"
#include <iostream>
int main () {
	HelloWorld hi = HelloWorld();
	hi.set("Hi Kelvin, Kymbreana, Casonya, Kevin, Tracy, Salena, Unique!");
	std::cout << hi.greet() << std::endl;
	return 0;
}
