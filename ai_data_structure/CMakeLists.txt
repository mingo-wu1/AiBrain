cmake_minimum_required(VERSION 3.5)
project(ai_data_structure)
set(CMAKE_CXX_STANDARD 11)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

option(BUILD_AI_DATA_STRUCTURE "Build ai data structure" TRUE)
if(BUILD_AI_DATA_STRUCTURE)
    add_executable(ai_hash_c ai_hash.c)
    install(TARGETS ai_hash_c RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
    add_executable(ai_hash_cpp ai_hash.cpp)
    install(TARGETS ai_hash_cpp RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
endif()