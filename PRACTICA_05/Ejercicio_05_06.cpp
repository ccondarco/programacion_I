// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 02/10/2025
// Número de ejercicio: 6
// Problema planteado: Declarar tres vectores de cinco enteros cada uno y pedir valores para los primeros dos para calcular la suma en el siguiente vector.


#include <iostream>
#include <vector>

using namespace std;

vector<int> ingresar_datos();
vector<int> suma_vectores(vector<int> vector1, vector<int> vector2);
void imprimir_vector(vector<int> vector);

int main()
{
    system("chcp 65001");
    system("cls");

    vector<int> primer_vector;
    vector<int> segundo_vector;
    vector<int> tercer_vector;

    cout << "Ingresar datos para primer vector" << endl;
    primer_vector = ingresar_datos();
    cout << endl;
    cout << "Ingresar datos para segundo vector" << endl;
    segundo_vector = ingresar_datos();

    tercer_vector = suma_vectores(primer_vector, segundo_vector);
    // Suma de los dos vectores, elemento por elemento.

    imprimir_vector(tercer_vector);

    return 0;
}

vector<int> ingresar_datos()
{
    vector<int> vector(5);

    for(int i = 0; i < 5; i++)
    {
        cout << "Ingresar el valor " << i + 1 << ": ";
        cin >> vector[i];
    }
    return vector;
}

vector<int> suma_vectores(vector<int> vector1, vector<int> vector2)
{
    vector<int> vector3(5);

    for(int i = 0; i < 5; i++){
        vector3[i] = vector1[i] + vector2[i];
    }
    return vector3;
}

void imprimir_vector(vector<int> vector)
// Se imprime el vector separando los elementos como en una tabla.
{
    cout << "La suma de los valores de cada vector es: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << vector[i] << "\t";
    }
    cout << endl;
}