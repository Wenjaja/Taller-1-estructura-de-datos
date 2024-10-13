//
// Created by benja on 16/09/2024.
//

#include "Revista.h"

#include <iostream>
#include <ostream>

Revista::Revista(const std::string& nombre, const std::string& isbn, const std::string& autor,const std::string& tipo, const int& numEdicion, const std::string& mesPublicacion)
    :MaterialBibliografico(nombre,isbn,autor,tipo), numEdicion(numEdicion), mesPublicacion(mesPublicacion)
{
    this->numEdicion = numEdicion;
    this->mesPublicacion = mesPublicacion;
}
std::string Revista::mostrarInfo() const
{
    std::string numEdicion = std::to_string(this->numEdicion);
    std::string info = MaterialBibliografico::mostrarInfo();
    info += "Numero de edicion: " + numEdicion + "\n";
    info += "Mes de publicacion: " + mesPublicacion + "\n";
    return info;
}
std::string Revista::getMesPublicacion() const
{
    return this->mesPublicacion;
}
int Revista::getNumEdicion() const
{
    return this->numEdicion;
}




