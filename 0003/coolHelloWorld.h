#include "helloWorld.h"

class CoolHelloWorld : public HelloWorld {
public:
	CoolHelloWorld() : coolmessage("Hiya!") {}
	virtual const std::string greet() const;
	virtual void set(const std::string);
private:
	std::string coolmessage;

};
