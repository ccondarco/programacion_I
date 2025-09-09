// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/09/2025
// Número de ejercicio: 4

#include <iostream>
#include <cmath>
using namespace std;

float indice_masa_corporal(float peso, float estatura);
// Función que calculará el Índice de Masa Corporal (IMC).
int main()
{
    system("chcp 65001");
    system("cls");
    float peso = 0.0;
    float estatura = 0.0;
    cout << "Ingresar peso en kg: ";
    cin >> peso;
    cout << "Ingresar estatura en metros: ";
    cin >> estatura;

    cout << "El Índice de Masa Corporal es: " << indice_masa_corporal(peso, estatura);
    return 0;
}

float indice_masa_corporal(float peso, float estatura)
{
    // La fórmula para calcular el IMC es (peso (kg) / [estatura (m)]^2).
    float IMC = 0.0;
    IMC = peso / pow(estatura, 2);
    return IMC;
}