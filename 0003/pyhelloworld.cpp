#include "coolHelloWorld.h"
#include <boost/python.hpp>
using namespace boost::python;
// Wrapper for pure virtual function
struct HelloWorldWrap : HelloWorld, wrapper<HelloWorld> {
	const std::string greet() const {
		return this->get_override("greet")();
	}
	void set(const std::string str) {}
};
BOOST_PYTHON_MODULE(pyhelloworld) {
        class_<HelloWorldWrap, boost::noncopyable>("HelloWorld")
		.def("greet", pure_virtual(&HelloWorld::greet))
		.def("set", pure_virtual(&HelloWorld::set))
        ;
	class_<CoolHelloWorld, bases<HelloWorldWrap> >("CoolHelloWorld")
		.def("greet", &CoolHelloWorld::greet)
		.def("set", &CoolHelloWorld::set)
	;
}
