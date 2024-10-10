#pragma once
#ifndef LIBRO_H
#define LIBRO_H
#include "MaterialBibliografico.h"
#include <iostream>
#include <string>

class Libro: public MaterialBibliografico {
    //Atributos de la clase
    private:
    std::string fechaPublicacion;
    std::string resumen;

    public:
    //Constructor
    Libro(const std::string& nombre, const std::string& isbn, const std::string& autor,const std::string& tipo,
        const std::string& fechaPublicacion, const std::string& resumen);
    //Metodo herdado de MaterialBibliografico, el cual se encarga de mostrar la informacion del libro
    std::string mostrarInfo() const override;
    //Getters
    [[nodiscard]] std::string getFechaPublicacion() const;
    [[nodiscard]] std::string getResumen() const;
};
#endif //LIBRO_H
