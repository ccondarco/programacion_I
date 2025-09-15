// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 14/09/2025
// Número de ejercicio: 2

#include <iostream>
using namespace std;

double calcular_volumen(double radio, double altura);
// La función devolverá el cálculo del volumen de un cilindro.
int main()
{
    system("chcp 65001");
    system("cls");
    double radio = 0.0;
    double altura = 10.0;
    double volumen = 0.0;

    cout << "Ingresar radio: ";
    cin >> radio;
    
    volumen = calcular_volumen(radio, altura);
    cout << "El volumen del cilíndro es: " << volumen;

    return 0;
}

double calcular_volumen(double radio, double altura)
{
    double volumen;
    volumen = 3.14159 * (radio * radio) *  altura;
    return volumen;
}