// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 02/10/2025
// Número de ejercicio: 4
// Problema planteado: Programar la multiplicación de dos vectores de dimensión N y mostrar los resultados en un vector diferente.


#include <iostream>
#include <vector>

using namespace std;

void ingresar_numeros(int dimension, vector<int>& primer_vector, vector<int>& segundo_vector);
vector<int> calcular_multiplicaciones(vector<int> primer_vector, vector<int> segundo_vector);
void imprimir_numeros(vector<int> primer_vector, vector<int> segundo_vector, vector<int> multiplicaciones);

int main()
{
    system("chcp 65001");
    system("cls");
    
    int dimension_vector;
    
    vector<int> numeros_primer_vector;
    vector<int> numeros_segundo_vector;
    vector<int> multiplicaciones;

    cout << "Ingresar la dimensión del vector: ";
    cin >> dimension_vector;

    ingresar_numeros(dimension_vector, numeros_primer_vector, numeros_segundo_vector);

    multiplicaciones = calcular_multiplicaciones(numeros_primer_vector, numeros_segundo_vector);

    imprimir_numeros(numeros_primer_vector, numeros_segundo_vector, multiplicaciones);
    
    
    return 0;
}

void ingresar_numeros(int dimension, vector<int>& primer_vector, vector<int>& segundo_vector)
{
    int numero;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            cout << "Ingresar numero para el vector " << i + 1 << ": ";
            cin >> numero;
        
            if (i == 0)
            // El valor de 'i' determina si el número ingresado se guarda en el primer o en el segundo vector.
            {
                primer_vector.push_back(numero);
            }
            else
            {
                segundo_vector.push_back(numero);
            }
        }
    }
}

vector<int> calcular_multiplicaciones(vector<int> primer_vector, vector<int> segundo_vector)
{
    int multiplicacion;
    vector<int> multiplicaciones;

    for (int i = 0; i < primer_vector.size(); i++)
    {
        multiplicacion = primer_vector[i] * segundo_vector[i];
        multiplicaciones.push_back(multiplicacion);
    }
    return multiplicaciones;
}

void imprimir_numeros(vector<int> primer_vector, vector<int> segundo_vector, vector<int> multiplicaciones)
// Se muestra los valores de ambos vectores junto con el resultado de sus multiplicaciones en formato de tabla.

{
    cout << "1er vector \t 2do vector \t Multiplicación" << endl;
    for (int i = 0; i < primer_vector.size(); i++)
    {
        cout << primer_vector[i] << "\t\t" << segundo_vector[i] << "\t\t" << multiplicaciones[i] << endl;
    }
}