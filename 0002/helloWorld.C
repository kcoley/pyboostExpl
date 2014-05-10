#include "helloWorld.h"
HelloWorld::HelloWorld() : msg("Hello, World") {}
HelloWorld::HelloWorld(std::string _msg) : msg(_msg) {}
std::string HelloWorld::greet() {
		return msg;
	}
void HelloWorld::set(std::string msg) { this->msg = msg; }
