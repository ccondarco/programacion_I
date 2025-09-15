// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 14/09/2025
// Número de ejercicio: 1

#include <iostream>
using namespace std;

void intercambiar_valores(int& valor1, int& valor2);

int main()
{
    system("chcp 65001");
    system("cls");

    int primer_valor;
    int segundo_valor;
    cout << "Ingresar primer valor: ";
    cin >> primer_valor;
    cout << "Ingresar segundo valor: ";
    cin >> segundo_valor;

    cout << "Primer valor antes del intercambio: " << primer_valor << endl;
    cout << "Segundo valor antes del intercambio: " << segundo_valor << endl;
    
    intercambiar_valores(primer_valor, segundo_valor);

    cout << "Primer valor después del intercambio: " << primer_valor << endl;
    cout << "Segundo valor después del intercambio: " << segundo_valor << endl;

    return 0;
}

void intercambiar_valores(int& valor1, int& valor2)
{
    int valor_temporal;
    // Se necesita una variable temporal para guardar el primer valor y no sobreescribirlo.
    valor_temporal = valor1;
    valor1 = valor2;
    valor2 = valor_temporal;
}