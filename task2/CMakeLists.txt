cmake_minimum_required(VERSION 3.1)

set (PROJECT task2) 
project (${PROJECT}) 

find_library(PTHREAD_LIBRARY pthread)
find_library(PCRE_LIBRARY pcre)


set (HEADERS robo.h Manager.h utils.h MqttClientFake.h MqttBrokerFake.h)
set (SOURCES Main.cpp	Manager.cpp robo.cpp MqttClientFake.cpp ) 

#include_directories(include)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -ldl"  ) # -Wall -Wextra -Werror

set(THREADS_PREFER_PTHREAD_FLAG ON)
#add_compile_options(-Wall -pthread -ldl -fPIC)
add_executable (${PROJECT} ${HEADERS} ${SOURCES} )

#target_link_libraries(main ${PTHREAD_LIBRARY} ${PCRE_LIBRARY})