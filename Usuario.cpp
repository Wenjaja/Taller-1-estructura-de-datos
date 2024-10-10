
#include "Usuario.h"

#include <iostream>
#include <ostream>
//Contructor
Usuario::Usuario(const std::string& nombre, const std::string& id)
{
    this->id = id;
    this->nombre = nombre;
    this ->cantLibros = 0;
}

//Métodos
void Usuario::prestarMaterial(MaterialBibliografico* materialAprestar)
{
    listaMaterial[cantLibros] = materialAprestar;
    cantLibros++;
    materialAprestar->setPrestado(false);
}
bool Usuario::devolverMaterial(const MaterialBibliografico* materialBuscado)
{
    int i = 0;
    for (MaterialBibliografico* material : this->listaMaterial)
    {
        if (material == materialBuscado)
        {
            listaMaterial[i] = nullptr;
            cantLibros--;
            material->setPrestado(true);
            return true;
        }
        i++;
    }
    return false;
}
std::string Usuario::mostrarMaterialesDeUsuario() const
{
    std::string resultado;

    for (int i = 0; i < cantLibros; ++i)
    {
        if (listaMaterial[i] != nullptr)
        {
            if (!resultado.empty())
            {
                resultado += ",";
            }
            resultado += listaMaterial[i]->getNombre() + "," + listaMaterial[i]->getIsbn();
        }
    }

    return resultado;
}

//Getters
std::string Usuario::getNombre() const
{
    return this -> nombre;
}
std::string Usuario::getId() const
{
    return this->id;
}
MaterialBibliografico* Usuario::getListaMaterial() const
{
    return *this -> listaMaterial;
}
int Usuario::getnumPrestados() const
{
    return this->cantLibros;
}
//Método para mostrar la información del usuario
std::string Usuario::mostrarInfo() const
{
    std::string info = "Nombre: " + this->nombre + "\n"
                           "Id: " + this->id + "\n";
    if(cantLibros > 0)
    {
        
        info += "Materiales prestados: " "\n";
        info += mostrarMaterialesDeUsuario();
        return info;
    }
    
    return info;
}

