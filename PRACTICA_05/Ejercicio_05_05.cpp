// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 02/10/2025
// Número de ejercicio: 5
// Problema planteado: Leer dos vectores de dimensión N y combinar ambos en otro vector.


#include <iostream>
#include <vector>

using namespace std;

vector<int> ingresar_numeros(int dimension);
vector<int> combinar_vectores(vector<int> vector1, vector<int> vector2);
void imprimir_vector(vector<int> vector);

int main()
{
    system("chcp 65001");
    system("cls");

    int dimension_vector;
    vector<int> primer_vector;
    vector<int> segundo_vector;
    vector<int> vector_combinado;

    cout << "Ingresar la dimensión de los vectores: ";
    cin >> dimension_vector;

    primer_vector = ingresar_numeros(dimension_vector);
    segundo_vector = ingresar_numeros(dimension_vector);
    // Se ingresan los valores del primer y segundo vector reutilizando la misma función.

    vector_combinado = combinar_vectores(primer_vector, segundo_vector);

    imprimir_vector(vector_combinado);
    return 0;
}

vector<int> ingresar_numeros(int dimension)
{
    int numero;
    vector<int> vector;
    for (int i = 0; i < dimension; i++)
    {
        cout << "Ingresar número para el vector " << i + 1 << ": ";
        cin >> numero;
        vector.push_back(numero);
    }
    return vector;
}

vector<int> combinar_vectores(vector<int> vector1, vector<int> vector2)
{
    vector<int> vector_combinado;

    for (int i = 0; i < vector1.size(); i++)
    {
        vector_combinado.push_back(vector1[i]);
    }
    
    for (int i = 0; i < vector2.size(); i++)
    {
        vector_combinado.push_back(vector2[i]);
    }
    
    return vector_combinado;
}

void imprimir_vector(vector<int> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << "\t";
    }
    cout << endl;
}