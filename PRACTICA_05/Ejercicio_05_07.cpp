// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 03/10/2025
// Número de ejercicio: 7
// Problema planteado: Ingresar números en un vector hasta llenarlo o ingresar un valor negativo, y mostrar solo los datos válidos.


#include <iostream>
#include <vector>

using namespace std;

vector<int> ingresar_numeros(int cantidad_maxima);
void imprimir_vector(vector<int> vector);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_maxima = 10;
    vector<int> numeros;
    
    numeros = ingresar_numeros(cantidad_maxima);

    imprimir_vector(numeros);

    return 0;
}

vector<int> ingresar_numeros(int cantidad_maxima)
{
    vector<int> numeros;
    int numero_ingresado;
    int contador = 0;

    cout << "Ingresar números." << endl;

    while (contador < cantidad_maxima)
    {
        cout << "Número " << contador + 1 << ": ";
        cin >> numero_ingresado;

        if (numero_ingresado >= 0)
        // Si el número es válido, se agrega al vector.
        {
            numeros.push_back(numero_ingresado);
            contador = contador + 1;
        }
        else
        // Si el número es negativo, se finaliza el programa.
        {
            cout << "No se puede ingresar un número negativo. Los números ingresados hasta ahora son:" << endl;
            contador = cantidad_maxima;
        }
    }
    return numeros;
}

void imprimir_vector(vector<int> numeros)
{
    for (int i = 0; i < numeros.size(); i++)
    {
        cout << numeros[i] << "\t";
    }
    cout << endl;
}