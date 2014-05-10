#include <iostream>
#include <boost/python.hpp>
using namespace boost::python;
class HelloWorld {
public:
	HelloWorld() : msg("Hello, World") {}
	HelloWorld(std::string _msg) : msg(_msg) {}
	std::string greet() {
		return msg;
	}
	void set(std::string msg) { this->msg = msg; }
private:
	std::string msg;

};

BOOST_PYTHON_MODULE(helloWorld) {
	class_<HelloWorld>("HelloWorld", init<>())
		.def(init<std::string>())
		.def("greet", &HelloWorld::greet)
		.def("set", &HelloWorld::set)
	;
}
