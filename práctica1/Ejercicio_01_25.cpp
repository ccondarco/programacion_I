// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/09/2025
// Número de ejercicio: 25

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero;
    int multiplicacion;
    char continuar;
    do
    // Bucle principal que se repite mientras el usuario quiera continuar.
    {
        cout << "Ingresar número cuya tabla de multiplicar se desea generar: ";
        cin >> numero;
        for (int i = 1; i <= 10; i++)
        // Bucle que recorre del 1 al 10 y muestra la tabla del número a multiplicar.
        {
            multiplicacion = numero * i;
            cout << numero << " x " << i << " = " << multiplicacion << endl;
        }
        cout << endl;
        cout << "¿Desea generar otra tabla? (s/n)" << endl;
        cin >> continuar;
    } while (continuar == 's');
    return 0;
}