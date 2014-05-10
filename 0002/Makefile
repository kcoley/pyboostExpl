# location of the Python header files
CC=clang++
CFLAGS=-c -Wall -fPIC 
PYTHON_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
 
# location of the Boost Python include files and library
 
BOOST_INC = /usr/include
BOOST_LIB = /usr/lib
 
# compile mesh classes
OBJECTS=helloWorld.o
TARGET = pyhelloworld
HELLOWORLDLIB=libhelloworld.so 
%.o: %.C
	clang++ -c -Wall -fPIC helloWorld.C

$(HELLOWORLDLIB): $(OBJECTS)
	$(CC) -shared -Wl,-soname,$(HELLOWORLDLIB) -o $(HELLOWORLDLIB) $(OBJECTS)

#$(TARGET).so: $(TARGET).o
#	clang++ -shared -Wl,--export-dynamic -lhelloworld -L$(BOOST_LIB) -lboost_python -L/usr/lib/python$(PYTHON_VERSION)/config -lboost_python -o $(TARGET).so
 
#$(TARGET).o: $(TARGET).cpp
#	clang++ -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC -c $(TARGET).cpp -lhelloworld

python:
	g++ -fPIC -I/usr/include/python2.7 -c pyhelloworld.cpp -o pyhelloworld.o
	g++ -shared -Wl,-soname,pyhelloworld.so -o pyhelloworld.so pyhelloworld.o -lpython2.7 -lboost_python -L. -lhelloworld
pythonsmart:
	$(CC) $(CFLAGS) -I$(PYTHON_INCLUDE) -c $(TARGET).cpp -o $(TARGET).o
	$(CC) -shared -Wl,-soname,$(TARGET).so -o $(TARGET).so $(TARGET).o -lpython2.7 -lboost_python -lhelloworld
clean:
	rm *.o
	rm *.so
