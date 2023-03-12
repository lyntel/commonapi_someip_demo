// HelloWorldClient.cpp
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloWorldProxy.hpp>

using namespace v1_0::commonapi;

int main() {
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::shared_ptr<HelloWorldProxy<>> myProxy =
    	runtime->buildProxy<HelloWorldProxy>("local", "test", "Hello");

    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable()){
        std::cout << "waiting  Available ... "<< std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    std::cout << "Available..." << std::endl;

    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    while (true)
    {
        std::cout << "call sayHello begin *******************" << std::endl;
        myProxy->sayHello("Bob", callStatus, returnMessage);
        std::cout << "Got message: '" << returnMessage << "'\n";
        std::cout << "call sayHello end *******************" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    
    return 0;
}