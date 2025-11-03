// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 31/10/2025
// Número de ejercicio: 1

#include <iostream>

using namespace std;

struct Libro
{
    char titulo[50];
    char autor[50];
    int anio_publicacion;
    bool disponible;
};

Libro ingresar_datos();
void desplegar_datos(Libro libro);

int main()
{
    system("chcp 65001");
    system("cls");

    Libro libro;

    cout << "Ingresar datos del libro" << endl;
    libro = ingresar_datos();

    desplegar_datos(libro);

    return 0;
}

Libro ingresar_datos()
// Esta función obtiene los datos de UN solo libro.
{
    Libro libro;
    char disponibilidad_escrita;
    // Se usa una variable temporal para transformar la disponibilidad ('s'/'n') a una variable booleana.

    cout << "Ingresar título: ";
    cin.getline(libro.titulo, 50);
    cout << "Ingresar autor: ";
    cin.getline(libro.autor, 50);
    cout << "Ingresar año de publicación: ";
    cin >> libro.anio_publicacion;
    cout << "Ingresar disponibilidad (s/n): ";
    cin >> disponibilidad_escrita;
    if (disponibilidad_escrita == 's' || disponibilidad_escrita == 'S')
    {
        libro.disponible = true;
    }
    else
    {
        libro.disponible = false;
    }
    
    return libro;
}

void desplegar_datos(Libro libro)
{
    cout << endl;
    cout << "\t Título: " << libro.titulo << endl;
    cout << "\t Autor: " << libro.autor << endl;
    cout << "\t Año de publicación: " << libro.anio_publicacion << endl;
    cout << "\t Disponibilidad: ";
    if (libro.disponible == true)
    {
        cout << "Libro disponible." << endl;
    }
    else
    {
        cout << "Libro no disponible." << endl;
    }
    cout << endl;
}