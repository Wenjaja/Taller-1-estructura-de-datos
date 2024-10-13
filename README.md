# Integrante
Benjamín Salas, 21.758.667-4, benjamin.salas02@alumnos.ucn.cl, Paralelo C2
# Simulador de Biblioteca Digital

El proyecto trata sobre un simulador de biblioteca digital que permite al encargado realizar diversas acciones, como la gestión de materiales bibliográficos y usuarios, la búsqueda de material, la administración de préstamos y devoluciones.

## Funcionalidades

### Agregar Material a la Biblioteca
Los usuarios pueden añadir libros y revistas con atributos específicos como título, autor, ISBN, y cada parametro en especifico de cada tipo.

### Mostrar Información de los Materiales
Se puede generar un listado detallado de todos los materiales presentes en la biblioteca.

### Buscar Material
Los usuarios pueden buscar materiales bibliográficos por título.

### Préstamo y Devolución de Material
Los usuarios pueden solicitar el préstamo de un máximo de cinco materiales a la vez, con la opción de devolverlos cuando lo deseen. El estado de los materiales se actualiza automáticamente tras cada operación.

### Gestión de Usuarios
El sistema permite crear, buscar y eliminar usuarios. Cada usuario tiene un registro de los materiales que ha solicitado en préstamo.

## Persistencia de Datos

El sistema permite guardar y cargar la información de la biblioteca y los usuarios desde archivos de texto utilizando la biblioteca `fstream` para garantizar la persistencia de datos.

## Estructura del Código

- **Lenguaje de Programación:** C++
- **Compilador:** g++
- **Estructura del Código:**
    - El código está organizado en múltiples archivos `.cpp` y `.h` para mantener una estructura modular y escalable.
    - Uso de punteros y arrays estáticos para la gestión de la memoria dinámica.

## Ejecución del Programa

Para compilar y ejecutar el programa, utiliza los siguientes comandos:

- **Compilar:** g++ -o Main MaterialBibliografico.cpp Libro.cpp Revista.cpp Usuario.cpp Sistema.cpp main.cpp
- **Ejecutar:** ./Main

### Ejemplo de Objetos Creados en el `main`

sistema = Sistema::getInstance(); sistema->cargarBiblioteca(); sistema->cargarUsuario();


El objeto `sistema` de tipo `sistema` gestiona la carga de datos mediante los metodos "cargarBiblioteca" y "cargarUsuarios".

### Ejemplo Datos de Prueba

En los archivos `biblioteca.txt` y `usuarios.txt` poseen datos con los que se pueden realizar las pruebas, aqui un ejemplo y su explicacion.

Bastian,4,0

Se presenta un `usuario` llamado `Bastian` de rut `4` y `0` materiales prestados.

Calculo,3,Maria,Libro,Disponible,23/7/2000,Ejercicios

Se presenta un `material` llamado `Calculo` con `ISBN "3"`, de `autor "Maria"`, de `tipo "Libro"`, con `estado "Disponible"`, `creado el "23/07/2000"`, con un `resumen "Ejercicios"`.
