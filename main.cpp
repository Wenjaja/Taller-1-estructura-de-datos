#include <iostream>
#include "Libro.h"
#include "Sistema.h"
using namespace std;
Sistema* sistema = nullptr; //atributo de sistema

void menu() //Función para desplegar el menú
{
    cout<<"hola"<<endl;
    cout<< "============================"<<endl;
    cout<< " Bienvenido a la biblioteca "<<endl;
    cout<< " Ingrese la opción que desea:"<<endl;
    cout<< " 1. Agregar Usuario."<<endl;
    cout<< " 2. Agregar Material (Libro/Revista)."<<endl;
    cout<< " 3. Prestar Materiales."<<endl;
    cout<< " 4. Devolver Materiales."<<endl;
    cout<< " 5. Mostrar Materiales."<<endl;
    cout<< " 6. Buscar Material."<<endl;
    cout<< " 7. Eliminar Usuario."<< endl;
    cout<< " 8. Mostrar Usuarios."<<endl;
    cout<< " 0. Salir."<<endl;
    cout<< " > ";
};
string verificarId() //Función para verificar que el id del usuario sea único
{
    string idValido;
    bool valido = false;
    do
    {
        cout << "Ingrese id del usuario: " << endl;
        cin >> idValido;
        if(sistema->validarParaIdNuevo(idValido))
        {
            valido = true;
        }
        else
        {
            cout << "El id ya existe, intente con otro! "<< endl;
        }
    } while (valido == false);
    cout << "Id valido! "<< endl;
    return idValido;
};
void crearUsuario()//Función para crear un usuario
{
    string nombreUsuario;
    cout<<"Ingrese nombre de usuario: " <<endl;
    cin>>nombreUsuario;
    string idUsuario = verificarId();
    cout<<sistema->crearUsuario(nombreUsuario,idUsuario)<<endl;
};
string verificarTipo() //Función para verificar que el tipo de material sea válido
{
    string tipoValido;
    bool valido = false;
    do
    {
        cout << "Ingrese tipo de material: ""\n"
                "1. Libro. \n"
                "2. Revista." <<endl;
        cin>>tipoValido;
        if(tipoValido == "1" || tipoValido == "2")
        {
            valido = true;
        }
        else
        {
            cout << "El tipo de material no valido! intente nuevamente "<< endl;
        }
    } while (valido == false);
    if (tipoValido == "1")
    {
        tipoValido = "Libro";
    }
    else
    {
        tipoValido = "Revista";
    }
    return tipoValido;
};
/*crearMaterial pide los datos del nuevo material
 *Dependiendo del tipo de material se guarda el parametro necesario
 *Luego imprime los casos posibles, ya sea que el material se agrego o que esta la lista de materiales esta llena.
 */
void crearMaterial()
{
    string nombreMaterial;
    string idMaterial;
    cout<<"Ingrese nombre del material: ";
    cin>>nombreMaterial;
    cout<<"Ingrese isbn del material: ";
    cin>>idMaterial;
    if(sistema->comprobarIsbn(idMaterial))
    {
        cout<<"El libro ya se encuentra en la biblioteca!"<< endl;
    }
    else
    {
        string parametro2;
        string parametro1;
        string nombreAutor;
        cout<<"Ingrese nombre del autor del material: ";
        cin>>nombreAutor;
        string tipoMaterial = verificarTipo();
        if (tipoMaterial == "Libro")
        {
            cout<<"Ingrese fecha de publicacion: ";
            cin>>parametro1;
            cout<<"Ingrese resumen: ";
            cin>>parametro2;
            cout<<sistema->crearMaterial(tipoMaterial, nombreMaterial,idMaterial, nombreAutor, parametro1, parametro2)<<endl;

        }
        else if(tipoMaterial == "Revista")
        {
            cout<<"Ingrese número de edicion: ";
            cin>>parametro1;
            cout<<"Ingrese mes de publicacion: ";
            cin>>parametro2;
            cout<<sistema->crearMaterial(tipoMaterial, nombreMaterial,idMaterial, nombreAutor, parametro1, parametro2)<<endl;
        }else{
            cout<<"Tipo de material no valido!"<<endl;
        }
    }


};
string validarIdExistente()//Función para verificar que el id de un usuario existente sea válido
{
    string idValido;
    cin>>idValido;
    bool valido = false;
    do
    {
        cout << "Ingrese id del usuario: " << endl;
        cin >> idValido;
        if(sistema->validarParaIdExistente(idValido))
        {
            valido = true;
        }
        else
        {
            cout << "El id no existe, intente con otro o agreguelo a la biblioteca! "<< endl;
        }
    } while (valido == false);
    cout << "Usuario encontrado! "<< endl;
    return idValido;

};
/*prestarMaterial pide el titulo del material que se desea y el id del usuario al cual se le prestará el material
 *Luego se revisa si el material está prestado, si no es asi se le presta el material.
 */
void prestarMaterial()
{
    string tituloMaterialBuscado;
    cout<<"Ingrese el titulo del material que desea prestar: ";
    cin>>tituloMaterialBuscado;
    const bool materialEncontrado = sistema->validarMaterialExistente(tituloMaterialBuscado);
    cout<<"Ingrese el id del usuario que desea asignar el material: ";
    string idUsuario;
    cin>>idUsuario;
    bool idValido = sistema->validarParaIdExistente(idUsuario);
    cout<<"si aqui"<<endl;
    if (idValido && materialEncontrado)
    {
        cout<<"aqui si entro a"<<endl;
        const string txt = sistema->prestarMaterial(tituloMaterialBuscado, idUsuario);
        cout<<"si"<<endl;
        cout<<txt<<endl;
    }else
    {
        cout<<"Titulo o id erroneos, intente nuevamente!"<<endl;
    }
};
//devolverMaterial pide el titulo del material que se desea devolver y el id del usuario el cual posea el material, para luego devolverlo.
void devolverMaterial()
{
    string tituloMaterialBuscado;
    cout<<"Ingrese el titulo del material que desea regresar: ";
    cin>>tituloMaterialBuscado;
    const bool materialEncontrado = sistema->validarMaterialExistente(tituloMaterialBuscado);
    string idUsuario;
    cout<<"Ingrese el id del usuario que tiene el material: ";
    cin>>idUsuario;
    bool idValido = sistema->validarParaIdExistente(idUsuario);
    if(idValido && materialEncontrado)
    {
        const string txt = sistema->devolverMaterial(tituloMaterialBuscado, idUsuario);
        cout<<txt<<endl;
    }else{
        cout<<"Titulo o id erroneos, intente nuevamente!"<<endl;
    }
};
//buscarMaterial pide el titulo del material que se desea buscar, para luego mostrar la información del material.
void buscarMaterial()
{
    string tituloMaterialBuscado;
    cout<<"Ingrese el titulo del material que busca: ";
    cin>>tituloMaterialBuscado;
    const bool materialEncontrado = sistema->validarMaterialExistente(tituloMaterialBuscado);
    if(materialEncontrado)
    {
        const string txt = sistema->mostrarMaterialBuscado(tituloMaterialBuscado);
        cout<<txt<<endl;
    }
    else
    {
        cout<<"Material no encontrado, intente nuevamente!"<<endl;
    }
};
//eliminarUsuario pide el id del usuario que se desea eliminar, para luego eliminarlo del sistema.
void eliminarUsuario()
{
    string idUsuario;
    cout<<"Ingrese el id del usuario que desea eliminar del sistema: ";
    cin>>idUsuario;
    const bool idValido = sistema->validarParaIdExistente(idUsuario);
    if(idValido)
    {
        cout<<sistema->eliminarUsuario(idUsuario)<<endl;
    }
    else
    {
        cout<<"Id no encontrado, intente nuevamente!"<<endl;
    }
};

int main()
{
    //Se genera la instancia de sistema
    sistema = Sistema::getInstance();
    sistema->cargarBiblioteca();
    sistema->cargarUsuario();

    bool salir = true;
    while(salir) //Ciclo para el menú
    {
        menu();
        int opcion;
        cin>>opcion;
        switch(opcion)//switch con los casos del menú
        {
            case 0:
                cout<<"Hasta pronto!!"<<endl;
                salir = false;
                sistema->guardarBiblioteca();
                sistema->guardarUsuario();
                break;
            case 1:
                crearUsuario();
                break;
            case 2:
                crearMaterial();
                break;
            case 3:
                prestarMaterial();
                break;
            case 4:
                devolverMaterial();
                break;
            case 5:
                cout<<sistema->mostrarMaterial()<<endl;
                break;
            case 6:
                buscarMaterial();
                break;
            case 7:
                eliminarUsuario();
                break;
            case 8:
                cout<<sistema->mostrarUsuario()<<endl;
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                break;
        }
    }
    delete sistema;
    return 0;
}