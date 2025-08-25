// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 15

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int cantidad_de_notas = 0;
    float nota = 0.0;
    float suma_de_notas = 0.0;
    float promedio_de_notas;
    cout << "Ingresar cantidad de notas a registrar: ";
    cin >> cantidad_de_notas;
    for (int i=1; i<=cantidad_de_notas; i++)
    // El bucle se repite hasta alcanzar el número de notas ingresado.
    {
        cout << "Ingresar nota: ";
        cin >> nota;
        suma_de_notas = suma_de_notas + nota;
        // Se acumulan en esta variable las notas ingresadas.
    }
    promedio_de_notas = suma_de_notas/cantidad_de_notas;
    // La suma de las notas acumuladas se divide entre la cantidad de notas para sacar el promedio.
    cout << promedio_de_notas;
    return 0;
}