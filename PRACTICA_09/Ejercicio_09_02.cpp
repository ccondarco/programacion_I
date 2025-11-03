// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 02/11/2025
// Número de ejercicio: 2

#include <iostream>

using namespace std;

struct Atleta
{
    char nombre[50];
    char pais[50];
    int edad;
    int mejor_tiempo;
};

Atleta ingresar_datos_atleta();
void ingresar_datos(int cantidad);
void desplegar_datos_atleta(Atleta atleta);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_atletas = 0;

    cout << "Ingresar cantidad de atletas: ";
    cin >> cantidad_atletas;

    ingresar_datos(cantidad_atletas);

    return 0;
}

Atleta ingresar_datos_atleta()
{
    Atleta atleta;

    cin.ignore();
    // Se usa cin.ignore() para limpiar el buffer que dejó la cantidad de atletas, antes de leer líneas con getline().
    cout << "Ingresar nombre: ";
    cin.getline(atleta.nombre, 50);
    cout << "Ingresar país: ";
    cin.getline(atleta.pais, 50);
    cout << "Ingresar edad: ";
    cin >> atleta.edad;
    cout << "Ingresar mejor tiempo (en segundos): ";
    cin >> atleta.mejor_tiempo;
    
    return atleta;
}

void ingresar_datos(int cantidad)
{
    Atleta atleta;
    
    Atleta atleta_con_mejor_tiempo;
    // Se inicializa una variable para poder guardar las estructuras del atleta con el mejor tiempo registrado.

    double mejor_tiempo = 100;
    // Se inicializa una variable para detectar el atleta con el mejor tiempo registrado.

    for (int i = 0; i < cantidad; i++)
    {
        atleta = ingresar_datos_atleta();
        cout << endl;

        if (atleta.mejor_tiempo < mejor_tiempo)
        {
            atleta_con_mejor_tiempo = atleta;
            mejor_tiempo = atleta.mejor_tiempo;
        }
    }
    
    cout << "El atleta con el mejor tiempo registrado:" << endl;
    desplegar_datos_atleta(atleta_con_mejor_tiempo);
}

void desplegar_datos_atleta(Atleta atleta)
{
    cout << "==========================================" << endl;
    cout << "\t Nombre: " << atleta.nombre << endl;
    cout << "\t País: " << atleta.pais << endl;
    cout << "\t Edad: " << atleta.edad << endl;
    cout << "\t Mejor tiempo (en segundos): " << atleta.mejor_tiempo << endl;
    cout << "==========================================" << endl;
}