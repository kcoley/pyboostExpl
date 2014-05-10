import helloWorld as hello
import datetime

greeter = hello.HelloWorld()
time = datetime.datetime.now()
greeter.set(str(time) + " Hello!")
print greeter.greet()
