#pragma once

#include "Usuario.h"
#ifndef SISTEMA_H
#define SISTEMA_H

class Sistema {
    //Atributos de la clase.
    private:
    static Sistema* instancia;// instancia del sistema.
    Usuario* listaUsuario[100];
    MaterialBibliografico* listaMaterial[100];
    int contMateriales;
    int contUsuarios;

    Sistema(); //Constructor.
    
    public:
    //Método que usa el patrón de diseño singleton en el sistema.
    static Sistema* getInstance();
    //Método para crear y agregar al usuario a la lista de usuarios.
    std::string crearUsuario( const std::string& nombre, const std::string& id);
    //Método que distingue que tipo de material es, lo crea y agrega a la lista de materiales.
    std::string crearMaterial(const std::string& tipo, const std::string& nombre,const std::string& id,const std::string& nombreAutor,const std::string& parametro1,const std::string& parametro2);
    //Método que crea los materiales desde el archivo de texto.
    std::string crearMaterialTXT(const std::string& tipo, const std::string& nombre,const std::string& id,const std::string& nombreAutor,const std::string& parametro1,const std::string& parametro2, const std::string& prestado);
    //Método para mostrar los materiales en la lista de materiales
    [[nodiscard]] std::string mostrarMaterial() const;
    //Método que recibe el id de un usuario de la lista, lo retorna si es que se encuentra en la lista, de lo contrario retorna nullptr.
    [[nodiscard]] Usuario* buscarUsuario(const std::string& id) const;
    //Método que recibe el titulo de un material de la lista, retorna el material si es que se encuentra en la lista, de lo contrario retorna nullptr.
    MaterialBibliografico* buscarMaterial(const std::string& titulo);
    //Método que recibe el id de un usuario de la lista, lo retorna si es que se encuentra en la lista, de lo contrario retorna nullptr.
    [[nodiscard]] Usuario* buscarUsuarioId(const std::string& id) const;
    //Metodo que recibe el titulo de un material y el id de un usuario, verifica si el material está prestado, si no lo está, se presta el material al usuario.
    std::string prestarMaterial(const std::string& titulo,const std::string& id);
    //Método que recibe el titulo de un material y el id de un usuario, verifica si el material está prestado, si lo está, se devuelve el material.
    std::string devolverMaterial(const std::string& titulo, const std::string& id);
    //Método que guarda la lista de materiales en un archivo.
    void guardarBiblioteca() const;
    //Método que guarda la lista de usuario en un archivo.
    void guardarUsuario() const;
    //Método que carga la lista de materiales desde un archivo.
    void cargarBiblioteca();
    //Método que carga la lista de usuarios desde un archivo.
    void cargarUsuario();
    //Método que verifica si un material está prestado.
    [[nodiscard]] bool verificarEstadoMaterial(const std::string& titulo);
    //Destructor
    ~Sistema();
    //Método que recibe el titulo de un material y lo muestra si es que se encuentra en la lista de materiales.
    [[nodiscard]] std::string mostrarMaterialBuscado(const std::string& titulo) const;
    //Método que recibe el id de un usuario y lo elimina si es que se encuentra en la lista de usuarios.
    [[nodiscard]] std::string eliminarUsuario(const std::string& idUsuario) const;
    //Método que recibe un id y verifica si es válido para ser un id nuevo.
    [[nodiscard]] bool validarParaIdNuevo(const std::string& idNuevo) const;
    //Método que recibe un isbn y verifica si es válido.
    [[nodiscard]] bool comprobarIsbn(const std::string& isbn) const;
    //Método que recibe un id de un usuario, verifica si este está en la lista y retorna true, de lo contrario retorna false.
    [[nodiscard]] bool validarParaIdExistente(const std::string& idExistente) const;
    //Método que recibe un isbn, verifica si este está en la lista de materiales y retorna true, de lo contrario retorna false.
    [[nodiscard]] bool validarMaterialExistente(const std::string& isbnExistente) const;
    //Método que muestra los usuarios de la biblioteca.
    [[nodiscard]] std::string mostrarUsuario() const;
};



#endif //SISTEMA_H
