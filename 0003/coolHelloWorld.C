#include "coolHelloWorld.h"

const std::string CoolHelloWorld::greet() const { return "Yo! " + coolmessage; }	
void CoolHelloWorld::set(const std::string msg) { this->coolmessage = msg; }	
