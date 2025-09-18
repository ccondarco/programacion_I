// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 15/09/2025
// Número de ejercicio: 7

#include <iostream>
using namespace std;

void intercambiar_numeros(int& m, int& n);
int MCD(int m, int n);
int MCM(int m, int n);

int main()
{
    system("chcp 65001");
    system("cls");

    int primer_numero_m;
    int segundo_numero_n;
    int mcd;
    int mcm;

    cout << "Ingresar primer número: ";
    cin >> primer_numero_m;
    cout << "Ingresar segundo número: ";
    cin >> segundo_numero_n;

    if (primer_numero_m == 0 || segundo_numero_n == 0)
    {
        cout << "No se puede calcular MCD o MCM si uno de los valores es cero.";
    }
        
    if (segundo_numero_n > primer_numero_m)
    {
        intercambiar_numeros(primer_numero_m, segundo_numero_n);
    }
    
    mcd = MCD(primer_numero_m, segundo_numero_n);
    cout << "El máximo común divisor es: " << mcd << endl;

    mcm = MCM(primer_numero_m, segundo_numero_n);
    cout << "El mínimo común múltiplo es: " << mcm << endl;

    return 0;
}

void intercambiar_numeros(int& m, int& n)
{
    int numero_temporal;
    
    numero_temporal = m;
    m = n;
    n = numero_temporal;
}

int MCD(int m, int n)
{
    int resto;
    while (n != 0)
    {
        resto = m % n;
        m = n;
        n = resto;
    }
    return m;
}

int MCM(int m, int n)
// El mínimo común múltiplo se puede sacar multiplicando los dos valores introducidos divididos entre su máximo común divisor.
{
    int mcm;
    mcm = (m * n) / MCD(m, n);
    return mcm;
}