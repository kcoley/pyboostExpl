#include "coolHelloWorld.h"
#include <boost/python.hpp>
using namespace boost::python;
// Wrapper for pure virtual function
template<typename T>
struct HelloWorldWrap : HelloWorld<T>, wrapper<HelloWorld<T> > {
	const std::string greet() const {
		return this->get_override("greet")();
	}
	void set(const std::string str) {}
};
template<typename T>
struct foo {
	T getVal() { return value; }
	void setVal(T val) { value = val; }
	T value;
};
template<typename T>
struct bar {
	virtual T getVal() = 0;
	virtual void setVal(T val) = 0;
};

template <typename T>
struct barWrap : bar<T>, wrapper<bar<T> > {
	T getVal() {
		return this->get_override("getVal")();
	}
	void setVal(T val) {}
};
template class barWrap<float>;
template <typename T>
void export_foo(std::string name) {
	class_<foo<T> >(name.c_str())
		.def("getVal", &foo<float>::getVal)
		.def("setVal", &foo<float>::setVal)
		
	;
}

template <typename T>
void export_bar(std::string name) {
	class_<barWrap<T> >(name.c_str())
		.def("getVal", pure_virtual(&bar<T>::getVal))
		.def("setVal", pure_virtual(&bar<T>::setVal))
		
	;
}
template <typename T>
void export_helloWorld(std::string name) {
	class_<HelloWorldWrap<T>, boost::noncopyable>(name.c_str())
		.def("greet", pure_virtual(&HelloWorld<T>::greet))
		.def("set", pure_virtual(&HelloWorld<T>::set))
	;
}
BOOST_PYTHON_MODULE(pyhelloworld) {
//	export_foo<float>("foo_float");
	export_bar<float>("bar_float");
//	export_helloWorld<float>("CoolHelloWorld");
//        class_<HelloWorldWrap<float>, boost::noncopyable>("HelloWorld")
//		.def("greet", pure_virtual(&HelloWorld<float>::greet))
//		.def("set", pure_virtual(&HelloWorld<float>::set))
  //      ;
//	class_<CoolHelloWorld<float>, bases<HelloWorldWrap<float> > >("CoolHelloWorld")
//		.def("greet", &CoolHelloWorld<float>::greet)
//		.def("set", &CoolHelloWorld<float>::set)
//	;
}
