#include <iostream>
class HelloWorld {
public:
	HelloWorld();
	HelloWorld(std::string _msg);
	std::string greet();
	void set(std::string msg);
private:
	std::string msg;

};
