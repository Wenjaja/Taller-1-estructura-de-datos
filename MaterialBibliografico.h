#pragma once
#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <string>

class MaterialBibliografico {
    //Atributos de la clase
    private:
    std::string nombre;
    std::string isbn;
    std::string autor;
    bool prestado = true;
    std::string tipo;
    public:
    //Constructor
    MaterialBibliografico(const std::string& nombre, const std::string&isbn, const std::string& autor,const std::string& tipo);
    //Metodo para heredar, que se encarga de mostrar la informacion del material
    virtual std::string mostrarInfo() const;
    //Destructor
    virtual ~MaterialBibliografico();
    //Getters
    [[nodiscard]] std::string getNombre() const;
    [[nodiscard]] std::string getIsbn() const;
    [[nodiscard]] std::string getAutor() const;
    [[nodiscard]] bool getPrestado() const;
    void setPrestado(bool estado);
    [[nodiscard]] std::string getTipo() const;
    //Metodo para mostrar si el material está prestado o no
    std::string esPrestado() const; 
};
#endif //MATERIALBIBLIOGRAFICO_H
