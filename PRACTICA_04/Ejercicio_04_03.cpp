// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 14/09/2025
// Número de ejercicio: 3

#include <iostream>
using namespace std;

void modificar_valores(int valor1, int& valor2, int& multiplicacion);
// Se tiene un tercer parámetro para poder desplegar no sólo el valor2 modificado, sino también la multiplicación del valor1.
int main()
{
    system("chcp 65001");
    system("cls");
    int valor1;
    int valor2;
    int multiplicacion;
    
    cout << "Ingresar primer valor: ";
    cin >> valor1;
    cout << "Ingresar segundo valor: ";
    cin >> valor2;

    modificar_valores(valor1, valor2, multiplicacion);

    cout << "Primer valor modificado: " << multiplicacion << endl;
    cout << "Segundo valor modificado: " << valor2 << endl;

    return 0;
}

void modificar_valores(int valor1, int& valor2, int& multiplicacion)
{
    multiplicacion = valor1 * 2;
    valor2 = valor2 + 10;
}