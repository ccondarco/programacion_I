// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 08/10/2025
// Número de ejercicio: 4

#include <iostream>
#include <vector>

using namespace std;

vector<int> ingresar_numeros(int cantidad_vector, vector<int>& numeros);
void rotar_vector(vector<int>& numeros, int cantidad_a_rotar);
void mostrar_vector(vector<int>& numeros);

int main()
{
	system("chcp 65001");
    system("cls");

    int cantidad_de_numeros;
	int cantidad_de_posiciones_a_rotar;
	vector<int> numeros;
	
	cout << "Ingresar cantidad de números que habrán en el vector: ";
	cin >> cantidad_de_numeros;
	cout << "Ingresar cantidad de posiciones a rotar: ";
	cin >> cantidad_de_posiciones_a_rotar;
	
    ingresar_numeros(cantidad_de_numeros, numeros);
    rotar_vector(numeros, cantidad_de_posiciones_a_rotar);

    cout << "Vector después de rotar: " << endl;
    mostrar_vector(numeros);
	
	return 0;
}

vector<int> ingresar_numeros(int cantidad_vector, vector<int>& numeros)
{
    int numero;
    for (int i = 0; i < cantidad_vector; i++)
    {
        cout << "Ingresar número: ";
        cin >> numero;
        numeros.push_back(numero);
    }
    return numeros;
}

void rotar_vector(vector<int>& numeros, int cantidad_a_rotar)
{
    int tamanio_vector_numeros = numeros.size();
    vector<int> numeros_reordenados;

    cantidad_a_rotar = cantidad_a_rotar % tamanio_vector_numeros;
    // Se asegura que la cantidad a rotar no sea mayor que el tamaño del vector.

    for (int i = tamanio_vector_numeros - cantidad_a_rotar; i < tamanio_vector_numeros; i++)
    // Los últimos elementos van al principio al rotarlos.
    {
        numeros_reordenados.push_back(numeros[i]);
    }

    for (int i = 0; i < tamanio_vector_numeros - cantidad_a_rotar; i++)
    // Luego se agregan los elementos restantes.
    {
        numeros_reordenados.push_back(numeros[i]);
    }
    
    for (int i = 0; i < tamanio_vector_numeros; i++)
    // Se copia el nuevo orden al vector original.
    {
        numeros[i] = numeros_reordenados[i];
    }
}

void mostrar_vector(vector<int>& numeros)
{
    for (int i = 0; i < numeros.size(); i++)
    {
        cout << numeros[i] << " ";
    }
    cout << endl;
}
