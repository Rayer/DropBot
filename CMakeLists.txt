cmake_minimum_required(VERSION 3.3)
project(DropBot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else(Boost_FOUND)
    message("No boost found!")
endif()

set(SOURCE_FILES main.cpp SampleDaemon.cpp SampleDaemon.h Daemonizer.h Daemonizer.cpp SignalHandler.cpp SignalHandler.h)
add_executable(DropBot ${SOURCE_FILES})
target_compile_definitions(DropBot PRIVATE)
target_link_libraries(DropBot ${Boost_LIBRARIES})
