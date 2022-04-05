cmake_minimum_required(VERSION 3.21)

project(webserv)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

file(GLOB SOURCE ${PROJECT_SOURCE_DIR}/srcs/*.cpp)
message(STATUS "${SOURCE}")

add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} PRIVATE includes)

#add_subdirectory(test)
