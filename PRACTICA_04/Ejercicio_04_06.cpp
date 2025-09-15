// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 14/09/2025
// Número de ejercicio: 6

#include <iostream>
using namespace std;

int suma_de_digitos(int numero);
bool es_primo(int numero);

int main()
{
    system("chcp 65001");
    system("cls");

    int numero;
    int digito;
    int suma_digitos = 0;
    
    cout << "Ingresar número: ";
    cin >> numero;
    
    suma_digitos = suma_de_digitos(numero);
    cout << "La suma de dígitos es: " << suma_digitos << endl;

    if (es_primo(numero) == true)
    {
        cout << "La suma de dígitos es un número primo.";
    }
    else
    {
        cout << "La suma de dígitos no es un número primo.";
    }
    
    return 0;
}


int suma_de_digitos(int numero)
{
    int digito;
    int suma = 0;
    while (numero > 0)
    {
        digito = numero % 10;
        if (digito != 0)
        {
            suma = suma + digito;
        }
        numero = numero / 10;
    }
    return suma;
}

bool es_primo(int numero)
{
    int suma;
    suma = suma_de_digitos(numero);
    // La función evalúa si la suma de los dígitos (obtenida por otra función) es un número primo.
    if (suma < 2)
    {
        return false;    
    }
    for (int i = 2; i < suma; i++)
    {
        if (suma % i == 0)
        {
            return false;
        }
    }
    return true;    
}