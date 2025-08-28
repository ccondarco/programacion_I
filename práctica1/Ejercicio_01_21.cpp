// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/08/2025
// Número de ejercicio: 21

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int primer_numero = 0;
    int segundo_numero = 0;
    int multiplicacion = 0;
    cout << "Ingrese el primer número a multiplicar: ";
    cin >> primer_numero;
    cout << "Ingrese el segundo número a multiplicar: ";
    cin >> segundo_numero;
    for(int i = 0; i < segundo_numero; i++)
    {
        multiplicacion = multiplicacion + primer_numero;
        // Se simula la multiplicación sumando el primer número tantas veces como indique el segundo.
    }
    cout << multiplicacion; 
    return 0;
}
