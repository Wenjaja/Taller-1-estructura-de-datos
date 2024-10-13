#include <iostream>
#include "Libro.h"
#include "MaterialBibliografico.h"
#include "Revista.h"
#include "Usuario.h"
#include "Sistema.h"
#include <fstream>
#include <sstream>
using namespace std;
Sistema* Sistema::instancia = nullptr;
Sistema::Sistema()
{
    for (int i = 0; i < 100; ++i) {
        listaUsuario[i] = nullptr;  // Inicializa cada puntero en la lista a nullptr para evitar algun tipo de error
        listaMaterial[i] = nullptr;  // Inicializa cada puntero en la lista a nullptr para evitar algun tipo de error
    }
}
Sistema* Sistema::getInstance()
{
    if (instancia==nullptr)
    {
        instancia = new Sistema();
    }
    return instancia;
}
std::string Sistema::crearUsuario(const std::string& nombreNuevoUsuario, const std::string& id)
{
    if(contUsuarios < 100)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (listaUsuario[i] == nullptr)
            {
                listaUsuario[i] = new Usuario(nombreNuevoUsuario, id);
                contUsuarios++;
                return "Usuario " + nombreNuevoUsuario + " registrado";

            }
        }
    }
    return "La lista de usuarios esta llena!";
}
std::string Sistema::crearMaterial(const std::string& tipo, const std::string& nombre,const std::string& id,const std::string& nombreAutor,const std::string& parametro1,const std::string& parametro2)
{
    if (contMateriales < 100)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (listaMaterial[i] == nullptr && tipo == "Libro")
            {
                listaMaterial[i] = new Libro(nombre, id, nombreAutor, tipo, parametro1, parametro2);
                contMateriales++;
                return "Libro " + nombre + " agregado correctamente!";
            }
            else if (listaMaterial[i] == nullptr && tipo == "Revista")
            {
                const int num = std::stoi(parametro1);
                listaMaterial[i] = new Revista(nombre, id, nombreAutor, tipo, num, parametro2);
                contMateriales++;
                return "Revista " + nombre + " agregada correctamente!";
            }
        }

    }

    return "La lista de materiales está llena!";
}
std::string Sistema::crearMaterialTXT(const std::string& tipo, const std::string& nombre,const std::string& id,const std::string& nombreAutor,const std::string& parametro1,const std::string& parametro2, const std::string& prestado)
{
    bool prestadoBool = true;
    if (prestado == "Prestado"){
        prestadoBool = false;
    }
    if (contMateriales < 100)
    {
        for (int i = 0; i < 100; ++i)
        {
            if (listaMaterial[i] == nullptr && tipo == "Libro")
            {
                listaMaterial[i] = new Libro(nombre, id, nombreAutor, tipo, parametro1, parametro2);
                listaMaterial[i]->setPrestado(prestadoBool);
                contMateriales++;
                return "Libro " + nombre + " agregado correctamente!";
            }
            else if (listaMaterial[i] == nullptr && tipo == "Revista")
            {
                const int num = std::stoi(parametro1);
                listaMaterial[i] = new Revista(nombre, id, nombreAutor, tipo, num, parametro2);
                listaMaterial[i]->setPrestado(prestadoBool);
                contMateriales++;
                return "Revista " + nombre + " agregada correctamente!";
            }
        }

    }

    return "La lista de materiales está llena!";
}
std::string Sistema::mostrarMaterial() const
{
    std::string txt = "Materiales de la biblioteca: \n";
    for(int i = 0; i < contMateriales; ++i)
    {
        if(listaMaterial[i] != nullptr)
        {
            txt+= listaMaterial[i]->mostrarInfo() + "\n";

        }
    }
    return txt;
}
std::string Sistema::prestarMaterial(const std::string& titulo,const std::string& id)
{
    Usuario* usuarioAux = buscarUsuarioId(id);
    if (usuarioAux == nullptr)
    {
        return "El usuario no existe, agreguelo a la biblioteca!";
    }
    MaterialBibliografico* materialAux = buscarMaterial(titulo);

    if(materialAux == nullptr)
    {
        return "El material no existe, agreguelo a la biblioteca";
    }

    if(materialAux->getPrestado() == false)
    {
        return "El material está prestado";
    }

    if(usuarioAux->getnumPrestados() >= 5)
    {
    return "El usuario no puede pedir prestado más libros, devuelva alguno e intente nuevamente!";
    }
    usuarioAux->prestarMaterial(materialAux);

    return "Material '" + titulo + "' prestado correctamente a " + usuarioAux->getNombre();
}
std::string Sistema::devolverMaterial(const std::string& titulo, const std::string& id)
{
    Usuario* usuario = buscarUsuarioId(id);
    if(usuario == nullptr)
    {
        return "El usuario no se encuentra en la lista, intente con alguno que si lo este o agreguelo!";
    }
    MaterialBibliografico* material = buscarMaterial(titulo);
    if(material == nullptr)
    {
        return "El material no se encuentra en la lista, intente con alguno que si lo este o agreguelo!";
    }
    if(material->getPrestado() == true)
    {
        return "El material no está prestado";
    }
    if(usuario->getnumPrestados() == 0)
    {
        return "El usuario no tiene materiales prestados";
    }
    bool confirmacion = usuario->devolverMaterial(material);
    if(confirmacion)
    {
        return "Material devuelto correctamente";
    }
    return "El material no se encuentra en la lista de materiales prestados por el usuario";

}
Usuario* Sistema::buscarUsuario(const std::string& nombre) const
{
    for(int i =0; i < 100; i++)
    {
        if(listaUsuario[i] != nullptr && this->listaUsuario[i]->getNombre() == nombre)
        {
            return this->listaUsuario[i];
        }
    }

    return nullptr;
}

MaterialBibliografico* Sistema::buscarMaterial(const std::string& titulo)
{
    for (MaterialBibliografico* material : listaMaterial)
    {
        if (titulo == material->getNombre())
        {
            return material;
        }
    }
    return nullptr;
}

Usuario* Sistema::buscarUsuarioId(const std::string& id) const
{
    for(int i =0; i < 100; i++)
    {
        if(listaUsuario[i] != nullptr && this->listaUsuario[i]->getId() == id)
        {
            return this->listaUsuario[i];
        }
    }
    return nullptr;
}

bool Sistema::verificarEstadoMaterial(const std::string& titulo)
{
    MaterialBibliografico* material = buscarMaterial(titulo);
    return material->getPrestado();
}
Sistema::~Sistema()
{
    for(int i=0; i < 100; i++)
    {
        if(listaMaterial[i] != nullptr)
        {
            delete listaMaterial[i];
            listaMaterial[i] = nullptr;
        }

    }
    for(int i=0; i < 100; i++)
    {
        if(listaUsuario[i] != nullptr)
        {
            delete listaUsuario[i];
            listaUsuario[i] = nullptr;
        }
    }

}
std::string Sistema::mostrarMaterialBuscado(const std::string& titulo) const
{
    std::string resultado;
    for (int i = 0; i < 100; ++i) {
        if (listaMaterial[i]->getNombre() == titulo) {
            resultado += "El Material fue encontrado con exito:\n " + listaMaterial[i]->mostrarInfo();
            return resultado;
        }
    }
    return "El Material no fue encontrado, intente de nuevo!";
}
std::string Sistema::eliminarUsuario(const std::string& idUsuario) const
{
    for( int i= 0; i < 100; i++)
    {
        if(listaUsuario[i] != nullptr && listaUsuario[i]->getId()==idUsuario)
        {
            if(listaUsuario[i]->getnumPrestados() > 0)
            {
                return "El usuario no se puede eliminar debido a que tiene materiales asociado, devuelva los materiales e intente de nuevo!";
            }
            delete listaUsuario[i];
            listaUsuario[i] == nullptr;
            return "Usuario eliminado correctamente";
        }
    }
    return "Usuario no encontrado";
}

bool Sistema::validarParaIdNuevo(const std::string& idAvalidar) const
{
    for (int i = 0; i < contUsuarios; ++i) {
        if (listaUsuario[i]->getId() == idAvalidar) {
            return false;
        }
    }
    return true;
}

bool Sistema::comprobarIsbn(const std::string& isbnAverificar) const
{
    for (int i = 0; i < contMateriales; ++i) {
        if (listaMaterial[i]->getIsbn() == isbnAverificar) {
            return true;
        }
    }
    return false;
}

bool Sistema::validarParaIdExistente(const std::string& idAvalidar) const
{
    for (int i = 0; i < contUsuarios; ++i) {
        if (listaUsuario[i]->getId() == idAvalidar) {
            return true;
        }
    }
    return false;
}

bool Sistema::validarMaterialExistente(const std::string& tituloAvalidar) const
{
    for (int i = 0; i < contMateriales; ++i)
    {
        if(listaMaterial[i]->getNombre() == tituloAvalidar)
        {
            return true;
        }
    }
    return false;

}

std::string Sistema::mostrarUsuario() const
{
    std::string txt = "Usuarios de la biblioteca: \n";
    for(int i = 0; i < 100; ++i)
    {
        if(listaUsuario[i] != nullptr)
        {
            txt+= listaUsuario[i]->mostrarInfo() + "\n";

        }
    }
    return txt;
}

std::string Sistema::mostrarUsuarioBuscado(const std::string& idBuscado) const
{
    std::string resultado;
    for (int i = 0; i < 100; ++i) {
        if (listaUsuario[i]->getId() == idBuscado) {
            resultado += "El Usuario fue encontrado con exito:\n " + listaUsuario[i]->mostrarInfo();
            return resultado;
        }
    }
    return "El Usuario no fue encontrado, intente de nuevo!";
}


void Sistema::guardarBiblioteca() const {
    std::ofstream archivo("biblioteca.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < 100; ++i) {
            if (listaMaterial[i] != nullptr) {
                archivo << listaMaterial[i]->getNombre() << ","
                        << listaMaterial[i]->getIsbn() << ","
                        << listaMaterial[i]->getAutor() << ","
                        << listaMaterial[i]->getTipo() << ","
                        << listaMaterial[i]->esPrestado();
                
                if (listaMaterial[i]->getTipo() == "Libro") {
                    Libro* libro = dynamic_cast<Libro*>(listaMaterial[i]);
                    if (libro != nullptr) {
                        archivo << "," << (libro->getFechaPublicacion().empty() ? " " : libro->getFechaPublicacion()) << ","
                                << (libro->getResumen().empty() ? " " : libro->getResumen());
                    }
                } else if (listaMaterial[i]->getTipo() == "Revista") {
                    Revista* revista = dynamic_cast<Revista*>(listaMaterial[i]);
                    if (revista != nullptr) {
                        archivo << "," << (std::to_string(revista->getNumEdicion()).empty() ? " " : std::to_string(revista->getNumEdicion())) << ","
                                << (revista->getMesPublicacion().empty() ? " " : revista->getMesPublicacion());
                    }
                }
                archivo << "\n";
            }
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar." << std::endl;
    }
}
void Sistema::cargarBiblioteca() {
    std::ifstream archivo("biblioteca.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string nombre, isbn, autor, tipo, parametro1, parametro2, prestado;
            std::getline(iss, nombre, ',');
            std::getline(iss, isbn, ',');
            std::getline(iss, autor, ',');
            std::getline(iss, tipo, ',');
            std::getline(iss, prestado, ',');
            std::getline(iss, parametro1, ',');
            std::getline(iss, parametro2, ',');

            crearMaterialTXT(tipo, nombre, isbn, autor, parametro1, parametro2, prestado);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para cargar." << std::endl;
    }
}
void Sistema::cargarUsuario() {
    std::ifstream archivoUsuarios("usuarios.txt");
    if (archivoUsuarios.is_open()) {
        std::string linea;
        while (std::getline(archivoUsuarios, linea)) {
            std::istringstream iss(linea);
            std::string nombre, id;
            int numPrestados;
            std::getline(iss, nombre, ',');
            std::getline(iss, id, ',');
            iss >> numPrestados;
            crearUsuario(nombre, id);

            Usuario* usuario = buscarUsuarioId(id);
            for (int i = 0; i < numPrestados; ++i) {
                std::string nombreMaterial, isbnMaterial;
                std::getline(iss, nombreMaterial, ',');
                std::getline(iss, isbnMaterial, ',');

                MaterialBibliografico* material = buscarMaterial(isbnMaterial);
                if (material != nullptr) {
                    usuario->prestarMaterial(material);
                } else {
                    std::cerr << "Material con ISBN " << isbnMaterial << " no encontrado en la biblioteca." << std::endl;
                }
            }

        }
        archivoUsuarios.close();
    } else {
        std::cerr << "No se pudo abrir el archivo de usuarios." << std::endl;
    }
}
void Sistema::guardarUsuario() const
{
    std::ofstream archivo("usuarios.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < 100; ++i) {
            if (listaUsuario[i] != nullptr) {

                archivo << listaUsuario[i]->getNombre() << ","
                        << listaUsuario[i]->getId() << ","
                        << listaUsuario[i]->getnumPrestados();


                if (listaUsuario[i]->getnumPrestados() > 0) {
                    std::string materiales = listaUsuario[i]->mostrarMaterialesDeUsuario();
                    archivo << "," << materiales;
                }
                archivo << "\n";
            }
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar los usuarios." << std::endl;
    }
}
