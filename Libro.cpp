
#include "Libro.h"
//Contructor material bibiliografico de tipo libro
Libro::Libro(const std::string& nombre, const std::string& isbn, const std::string& autor,const std::string& tipo, const std::string& fechaPublicacion, const std::string& resumen)
: MaterialBibliografico(nombre,isbn,autor,tipo), fechaPublicacion(fechaPublicacion), resumen(resumen)
{
    this -> fechaPublicacion = fechaPublicacion;
    this -> resumen = resumen;

}
//Metodo heredado de MaterialBibliografico
std::string Libro::mostrarInfo() const
{
    return MaterialBibliografico::mostrarInfo() + "Fecha Publicacion: " + fechaPublicacion + "\n"
    + "Resumen: " + resumen + "\n";
}
//Getters
std::string Libro::getResumen() const
{
    return this->resumen;
}

std::string Libro::getFechaPublicacion() const
{
    return this->fechaPublicacion;
}

