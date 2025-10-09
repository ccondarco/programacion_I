// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 08/10/2025
// Número de ejercicio: 5

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool esta_en_lista(string nombre, vector<string>& lista);
void mostrar_vector(vector<string>& lista);

int main()
{
    system("chcp 65001");
    system("cls");

    vector<string> lista_A = {"Luciana", "Mario", "Diana", "Ernesto", "Majo"};
    vector<string> lista_B = {"Christian", "Luciana", "Ernesto", "Majo", "Luis"};
    vector<string> clientes_en_comun;
    string cliente_actual_A;
    string cliente_actual_B;
    bool ya_esta_en_la_lista;

    for (int i = 0; i < lista_A.size(); i++)
    {
        for (int j = 0; j < lista_B.size(); j++)
        {
            cliente_actual_A = lista_A[i];
            cliente_actual_B = lista_B[j];
            // Se guardan los valores actuales de A y B en variables temporales.
            if (cliente_actual_A == cliente_actual_B)
            {
                ya_esta_en_la_lista = esta_en_lista(cliente_actual_A, clientes_en_comun);
                // Se verifica si el nombre ya fue agregado a la lista de clientes en común.
                if (ya_esta_en_la_lista == false)
                {
                    clientes_en_comun.push_back(cliente_actual_A);
                }
            }
        }
    }

    cout << "Clientes en común: ";
    mostrar_vector(clientes_en_comun);

    return 0;
}

bool esta_en_lista(string nombre, vector<string>& lista)
{
    for (int i = 0; i < lista.size(); i++)
    {
        if (lista[i] == nombre)
        {
            return true;
        }
    }
    return false;
}

void mostrar_vector(vector<string>& lista)
{
    for (int i = 0; i < lista.size(); i++)
    {
        cout << lista[i];
        if (i != lista.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}