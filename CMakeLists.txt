cmake_minimum_required(VERSION 3.29)
project(Taller_1_Estructura_de_Datos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller_1_Estructura_de_Datos main.cpp
        Usuario.cpp
        Usuario.h
        MaterialBibliografico.cpp
        MaterialBibliografico.h
        Libro.cpp
        Libro.h
        Revista.cpp
        Revista.h
        Sistema.cpp
        Sistema.h)
