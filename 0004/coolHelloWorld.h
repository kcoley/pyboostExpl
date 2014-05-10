#include "helloWorld.h"

template <typename T>
class CoolHelloWorld : public HelloWorld<T> {
public:
	CoolHelloWorld() : coolmessage("Hiya!"), value() {}
	virtual const std::string greet() const { return "Yo! " + coolmessage; }
	virtual void set(const std::string msg) { this->coolmessage = msg; }
	virtual T getValue() { return value;}
private:
	std::string coolmessage;
	T value;
};
