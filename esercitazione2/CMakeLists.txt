cmake_minimum_required(VERSION 3.20)
project(Esercitazione_2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")



#primo esercizio
add_executable(primi_algoritmi primi_algoritmi.cpp)

#secondo esercizio
add_executable(bubblesort bubblesort.cpp)
