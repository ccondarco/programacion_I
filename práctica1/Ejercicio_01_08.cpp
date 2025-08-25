// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 23/08/2025
// Número de ejercicio: 8

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    int resultado = 0;
    cout << "Ingresar número: ";
    cin >> numero;
    if (numero%2 == 0)
    // Para saber si es número par, el residuo debería ser cero al dividir el número entre dos.
    {
        cout << "Número par.";
    }
    else
    {
        cout << "Número impar.";
    }
    return 0;
}