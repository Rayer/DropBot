cmake_minimum_required(VERSION 3.3)
project(DropBot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
#find_package(Boost 1.55.0 REQUIRED COMPONENTS program_options)
#
#if(Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIRS})
#endif()

set(SOURCE_FILES main.cpp SampleDaemon.cpp SampleDaemon.h Daemonlizer.h)
add_executable(DropBot ${SOURCE_FILES})
#target_link_libraries(DropBot ${Boost_LIBRARIES})