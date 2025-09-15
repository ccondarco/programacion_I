// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 14/09/2025
// Número de ejercicio: 4

#include <iostream>
using namespace std;

double convertir_celsius_a_farenheit(double celsius);
// La función hace la conversión de grados Celsius a Farenheit.
double mayor_temperatura(double valor1, double valor2);
// La función devuelve el valor más grande introducido.
int main()
{
    system("chcp 65001");
    system("cls");

    double grados_celsius;
    double temperatura1;
    double temperatura2;
    cout << "Ingresar grados Celsius: ";
    cin >> grados_celsius;

    grados_celsius = convertir_celsius_a_farenheit(grados_celsius);
    cout << "La conversión de grados Celsius a Farenheit es: " << grados_celsius << endl << endl;

    cout << "Ingresar valor de la primera temperatura: ";
    cin >> temperatura1;
    cout << "Ingresar valor de la segunda temperatura: ";
    cin >> temperatura2;

    cout << "La temperatura más alta es: " << mayor_temperatura(temperatura1, temperatura2);
    return 0;
}

double convertir_celsius_a_farenheit(double celsius)
{
    double grados_farenheit;
    grados_farenheit = (celsius * 1.8) + 32.0;
    return grados_farenheit;
}

double mayor_temperatura(double valor1, double valor2)
{
    if (valor1 > valor2)
    {
        return valor1;
    }
    else
    {
        return valor2;
    }
}