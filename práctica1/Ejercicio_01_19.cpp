// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 26/08/2025
// Número de ejercicio: 19

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    int multiplicacion;
    cout << "Ingresar número del 1 al 10 para multiplicar: ";
    cin >> numero;
    while (numero < 1 || numero > 10)
    // Se Valida que el número esté en el rango permitido.
    {
        cout << "Número inválido, debe estar entre 1 y 10. Introducir nuevo número: ";
        cin >> numero;
    }
    for (int i=1; i<=10; i++)
    {
        multiplicacion = numero*i;
        cout << numero << " x " << i << " = " << multiplicacion << endl;
    }
    return 0;
}