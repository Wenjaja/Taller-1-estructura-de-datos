#pragma once
#ifndef REVISTA_H
#define REVISTA_H
#include "MaterialBibliografico.h"
#include <string>

class Revista: public MaterialBibliografico {
    //Atributos de la clase
    private:
        int numEdicion;
        std::string mesPublicacion;
    public:
        //Construtor
        Revista(const std::string& nombre, const std::string& isbn, const std::string& autor,const std::string& tipo, const int& numEdicion, const std::string& mesPublicacion );
        //Metodo heredado de MaterialBibliografico, el cual se encarga de mostrar la informacion de la revista
        [[nodiscard]] std::string mostrarInfo() const override;
        //Getters
        [[nodiscard]] int getNumEdicion() const;
        [[nodiscard]] std::string getMesPublicacion() const;
};

#endif //REVISTA_H
