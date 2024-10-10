#pragma once

#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "MaterialBibliografico.h"

class Usuario {
    //Atributos de la clase
    private:
    std::string nombre;
    std::string id;
    MaterialBibliografico* listaMaterial[5]{};
    int cantLibros;
    public:
    //Constructor
    Usuario(const std::string& nombre, const std::string& id);
    //Método para prestar un material al usuario
    void prestarMaterial(MaterialBibliografico* material);
    //Método para devolver un material al usuario
    bool devolverMaterial(const MaterialBibliografico* material);
    //Método para mostrar los materiales prestados por el usuario
    std::string mostrarMaterialesDeUsuario() const;
    //getters
    [[nodiscard]] std::string getId() const;
    [[nodiscard]] std::string getNombre() const;
    [[nodiscard]] MaterialBibliografico* getListaMaterial() const;
    [[nodiscard]] int getnumPrestados() const;
    //Método para mostrar la información del usuario
    std::string mostrarInfo() const;

};



#endif //USUARIO_H
