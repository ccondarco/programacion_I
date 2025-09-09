// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 06/09/2025
// Número de ejercicio: 1

#include <iostream>
using namespace std;

string par_o_impar(int valor);
// Función que indicará si el número es par o impar.
int main()
{
    system("chcp 65001");
    system("cls");

    int numero = 0;
    cout << "Ingresar número: ";
    cin >> numero;

    cout << "El número " << numero << par_o_impar(numero);
    return 0;
}

string par_o_impar(int valor)
{
    if (valor % 2 == 0)
    {
        return " es par.";
    }
    else
    {
        return " es impar.";
    }
}