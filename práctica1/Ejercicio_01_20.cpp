// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 26/08/2025
// Número de ejercicio: 20

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    int digitos = 0;
    cout << "Ingresar número: ";
    cin >> numero;
    while (numero > 0)
    {
        digitos = digitos + 1;
        numero = numero / 10;
        // Esta operación elimina el último dígito del número.
    }
    cout << "Cantidad de dígitos: " << digitos;
    return 0;
}