// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 23/08/2025
// Número de ejercicio: 5

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    // Fórmula: Kelvin = Celsius + 273.15
    float grados_celsius = 0.0;
    float grados_kelvin = 0.0;
    cout << "Ingresar grados Celsius: ";
    cin >> grados_celsius;
    grados_kelvin = (grados_celsius + 273.15);
    cout << "Temperatura en grados Kelvin: " << grados_kelvin;
    return 0;
}