#include "helloWorld.h"
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(pyhelloworld) {
        class_<HelloWorld>("HelloWorld", init<>())
                .def(init<std::string>())
                .def("greet", &HelloWorld::greet)
                .def("set", &HelloWorld::set)
        ;
}
