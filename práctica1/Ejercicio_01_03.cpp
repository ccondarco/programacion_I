// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 22/08/2025
// Número de ejercicio: 3

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    // El área de un triángulo es la multiplicación de la base del mismo por la altura, éstos divididos por 2.
    int base = 0;
    int altura = 0;
    int area = 0;
    cout << "Ingresar base: ";
    cin >> base;
    cout << "Ingresar altura: ";
    cin >> altura;
    area = (base*altura)/2;
    cout << "Área de triángulo: " << area;
}