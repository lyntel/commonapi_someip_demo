set(TARGET HelloWorld)
set(SOMEIP_LIBS CommonAPI CommonAPI-SomeIP vsomeip)

set(HelloWorld_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/v1/commonapi)

# HelloWorldCore library
set(SOMEIP_STUB_SRCS
    ${HelloWorld_SRC_DIR}/HelloWorldSomeIPDeployment.cpp
    ${HelloWorld_SRC_DIR}/HelloWorldSomeIPStubAdapter.cpp 
    #${HelloWorld_SRC_DIR}/HelloWorldStubDefault.cpp
)

add_library(${TARGET}Core SHARED ${SOMEIP_STUB_SRCS})
target_include_directories(${TARGET}Core 
    PUBLIC 
    .)

target_link_libraries(${TARGET}Core ${SOMEIP_LIBS})

target_compile_options(${TARGET}Core PRIVATE -fPIC)
set_target_properties(${TARGET}Core PROPERTIES SOVERSION 1 VERSION 1.0.0)

# HelloWorldSomeIP library
set(SOMEIP_PROXY_SRCS ${HelloWorld_SRC_DIR}/HelloWorldSomeIPDeployment.cpp
                      ${HelloWorld_SRC_DIR}/HelloWorldSomeIPProxy.cpp
)

add_library(${TARGET}SomeIP SHARED ${SOMEIP_PROXY_SRCS})
target_include_directories(${TARGET}SomeIP 
    PUBLIC 
    .)
target_link_libraries(${TARGET}SomeIP ${SOMEIP_LIBS})

target_compile_options(${TARGET}SomeIP PRIVATE -fPIC)
set_target_properties(${TARGET}SomeIP PROPERTIES SOVERSION 1 VERSION 1.0.0)

message(STATUS "src-gen EOF")
