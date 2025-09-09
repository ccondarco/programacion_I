// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/09/2025
// Número de ejercicio: 5

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float promedio_ponderado(float total_suma, float total_ponderaciones);
// La función calculará el promedio ponderado.
int main()
{
    system("chcp 65001");
    system("cls");

    float primera_calificacion = 0;
    float segunda_calificacion = 0;
    float tercera_calificacion = 0;
    float cuarta_calificacion = 0;
    float suma_ponderada = 0;
    float suma_ponderaciones = 0;

    srand(time(0));

    primera_calificacion = (rand() % 100) + 1;
    cout << "Primera calificación: " << primera_calificacion << endl;
    segunda_calificacion = (rand() % 100) + 1;
    cout << "Segunda calificación: " << segunda_calificacion << endl;
    tercera_calificacion = (rand() % 100) + 1;
    cout << "Tercera calificación: " << tercera_calificacion << endl;
    cuarta_calificacion = (rand() % 100) + 1;
    cout << "Cuarta calificación: " << cuarta_calificacion << endl;

    suma_ponderada = (primera_calificacion * 10) + (segunda_calificacion * 20) + (tercera_calificacion * 30) + (cuarta_calificacion * 40);
    // La suma ponderada es cada calificación multiplicada por la ponderación que tiene.
    suma_ponderaciones = 10 + 20 + 30 + 40;

    cout << "El promedio ponderado es: " << promedio_ponderado(suma_ponderada, suma_ponderaciones);
    return 0;
}

float promedio_ponderado(float total_suma, float total_ponderaciones)
{
    float promedio = 0;
    promedio = total_suma / total_ponderaciones;
    return promedio;
}