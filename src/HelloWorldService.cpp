// HelloWorldService.cpp
#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
// #include <CommonAPI/Logger.hpp>

#include "HelloWorldStubImpl.hpp"

using namespace std;

int main() {
    // CommonAPI::Runtime::setProperty("LibraryBase","HelloWorld");

    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<HelloWorldStubImpl> myService =
    	std::make_shared<HelloWorldStubImpl>();
        std::string domain = "local";
        std::string instance = "test"; //depl service define compare 
        std::string connection = "APP2";  //application_name 
    runtime->registerService(domain, instance, myService,connection);
    std::cout << "Successfully Registered Service!" << std::endl;
    
    // COMMONAPI_INFO("***TEST COMMONAPI LOG INFO ****** \'");

    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }
    return 0;
 }