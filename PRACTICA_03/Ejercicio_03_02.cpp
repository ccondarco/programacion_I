// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/09/2025
// Número de ejercicio: 2

#include <iostream>
using namespace std;

float celsius_a_farenheit(float valor);
// Función que convertirá de grados Celsius a Farenheit.
int main()
{
    system("chcp 65001");
    system("cls");

    float temperatura = 0.0;
    cout << "Ingresar temperatura Celsius: ";
    cin >> temperatura;

    cout << temperatura << "° Celsius equivalen a " << celsius_a_farenheit(temperatura) << "° Farenheit.";
    
    return 0;
}

float celsius_a_farenheit(float valor)
{
    // Fórmula para convertir de grados Celsius a Farenheit: °F = (°C x 9/5) + 32.
    float grados_farenheit = 0.0;
    grados_farenheit = (valor * 1.8) + 32;
    return grados_farenheit;
}