#include <iostream>
template <typename T>
class HelloWorld {
public:
	virtual const std::string greet() const = 0;
	virtual void set(const std::string) = 0;
	virtual T getValue() = 0;
};

