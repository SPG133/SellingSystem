cmake_minimum_required(VERSION 3.10.0)
project(main)
set(MOD_MY_CALCULATION_PATH ${CMAKE_SOURCE_DIR}/MyClass)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
aux_source_directory(${MOD_MY_CALCULATION_PATH} MOD_MY_CALCULATION_SRC)
#link_directories(lib)
include_directories(bin)
add_library(product STATIC ${MOD_MY_CALCULATION_SRC})


aux_source_directory(${CMAKE_SOURCE_DIR} RP_ALL_SRC)

add_executable(main ${RP_ALL_SRC} )

target_link_libraries(main product)


