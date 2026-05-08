cmake_minimum_required(VERSION 3.20)
project(esercitazione6)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Creo il target per l'eseguibile principale del mio progetto software
set(SOURCES unidirected_edge.hpp unidirected_graph.hpp prova.cpp)
#Creo una variabile chiamata graph e memorizzo al suo interno gli eseguibili
add_executable(esercitazione6 ${SOURCES})
