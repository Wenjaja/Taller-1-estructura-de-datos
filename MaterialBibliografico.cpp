#include "MaterialBibliografico.h"

#include <iostream>
#include <ostream>
//Constructor
MaterialBibliografico::MaterialBibliografico(const std::string& nombre, const std::string& isbn, const std::string& autor,const std::string& tipo)
{
    this->nombre = nombre;
    this->isbn = isbn;
    this->autor = autor;
    this->tipo = tipo;
}
//Métodos
std::string MaterialBibliografico::mostrarInfo() const
{
    std::string esPrestado;
    if(prestado)
    {
        esPrestado = "Disponible";
    }
    else
    {
        esPrestado = "Prestado";
    }
    return "Titulo: " + nombre + "\n" +
        "Autor: " + autor + "\n" +
            "Isbn: " + isbn + "\n" +
                "Tipo: " + tipo + "\n" +
                    "Estado: " + esPrestado + "\n";
}
//Destructor
MaterialBibliografico::~MaterialBibliografico()
= default;
//Getters
std::string MaterialBibliografico::getAutor() const
{
    return this->autor;
}
std::string MaterialBibliografico::getNombre() const
{
    return this->nombre;
}
std::string MaterialBibliografico::getIsbn() const
{
    return this->isbn;
}

bool MaterialBibliografico::getPrestado() const
{
    
    return this->prestado;
}
void MaterialBibliografico::setPrestado(const bool estado)
{
    this->prestado = estado;
}

std::string MaterialBibliografico::getTipo() const
{
    return this->tipo;
}
std::string MaterialBibliografico::esPrestado() const
{
    if(prestado)
    {
        return "Disponible";
    }
    else
    {
        return "Prestado";
    }
}




