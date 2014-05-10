#include <iostream>
class HelloWorld {
public:
	virtual const std::string greet() const = 0;
	virtual void set(const std::string) = 0;
};

