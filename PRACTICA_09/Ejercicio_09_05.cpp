// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/11/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Pelicula
{
    char titulo[50];
    char director[50];
    int duracion;
    int anio_estreno;
    char genero[20];
};

Pelicula ingresar_datos_pelicula();
void ingresar_datos(vector<Pelicula>& peliculas, int cantidad);
void desplegar_datos_pelicula(Pelicula pelicula);
void mostrar_lista_genero(vector<Pelicula> peliculas, char campo_ingresado[20]);
void mostrar_lista_director(vector<Pelicula> peliculas, char campo_ingresado[50]);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_peliculas;
    vector<Pelicula> lista_peliculas;
    char genero[20];
    char director[50];

    cout << "Ingresar cantidad de películas: ";
    cin >> cantidad_peliculas;
    cin.ignore();
    // Limpia el salto de línea para poder introducir todas las películas, de lo contrario, sólo se puede introducir una.

    ingresar_datos(lista_peliculas, cantidad_peliculas);

    cout << "Ingresar el género de películas a desplegar: ";
    cin.getline(genero, 20);
    cout << endl;
    cout << "Películas de " << genero << endl;
    cout << endl;
    mostrar_lista_genero(lista_peliculas, genero);

    cout << endl;

    cout << "Ingresar el director de películas a desplegar: ";
    cin.getline(director, 50);
    cout << endl;
    cout << "Películas dirigidas por " << director << endl;
    cout << endl;
    mostrar_lista_director(lista_peliculas, director);

    return 0;
}

Pelicula ingresar_datos_pelicula()
{
    Pelicula pelicula;

    cout << "Ingresar título de película: ";
    cin.getline(pelicula.titulo, 50);
    cout << "Ingresar director: ";
    cin.getline(pelicula.director, 50);
    cout << "Ingresar duración: ";
    cin >> pelicula.duracion;
    cout << "Ingresar año de estreno: ";
    cin >> pelicula.anio_estreno;
    cin.ignore();
    cout << "Ingresar género: ";
    cin.getline(pelicula.genero, 20);

    return pelicula;
}

void ingresar_datos(vector<Pelicula>& peliculas, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        peliculas.push_back(ingresar_datos_pelicula());
        cout << endl;
    }
}

void desplegar_datos_pelicula(Pelicula pelicula)
{
    cout << "==========================================" << endl;
    cout << "Título: " << pelicula.titulo << endl;
    cout << "Director: " << pelicula.director << endl;
    cout << "Duración: " << pelicula.duracion << endl;
    cout << "Año de Estreno: " << pelicula.anio_estreno << endl;
    cout << "Género: " << pelicula.genero << endl;
    cout << "==========================================" << endl;
}

void mostrar_lista_genero(vector<Pelicula> peliculas, char campo_ingresado[20])
{
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (strcmp(campo_ingresado, peliculas[i].genero) == 0)
        // strcmp compara las cadenas y, si éstas son iguales, deben devolver 0.
        {
            desplegar_datos_pelicula(peliculas[i]);
        }
    }
}

void mostrar_lista_director(vector<Pelicula> peliculas, char campo_ingresado[50])
{
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (strcmp(campo_ingresado, peliculas[i].director) == 0)
        {
            desplegar_datos_pelicula(peliculas[i]);
        }
    }
}