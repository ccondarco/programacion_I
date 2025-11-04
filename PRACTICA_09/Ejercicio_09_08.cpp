// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/11/2025
// Número de ejercicio: 8

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string.h>

using namespace std;

struct Atleta
{
    char nombre[50];
    char departamento[15];
    char deporte[15];
    int medallas;
};

Atleta ingresar_datos_atleta();
void ingresar_datos(vector<Atleta>& atletas, int cantidad);
void desplegar_datos_atleta(Atleta atleta);
void mostrar_medallero(const vector<Atleta>& lista_atletas);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_atletas = 0;
    vector<Atleta> lista_atletas;

    cout << "Ingresar cantidad de atletas: ";
    cin >> cantidad_atletas;
    cin.ignore();

    srand(time(0));

    ingresar_datos(lista_atletas, cantidad_atletas);

    cout << "MEDALLERO POR DEPARTAMENTO" << endl;
    cout << endl;
    mostrar_medallero(lista_atletas);

    return 0;
}

Atleta ingresar_datos_atleta()
{
    Atleta atleta;

    cout << "Nombre del atleta: ";
    cin.getline(atleta.nombre, 50);
    cout << "Departamento: ";
    cin.getline(atleta.departamento, 20);
    cout << "Deporte practicado: ";
    cin.getline(atleta.deporte, 20);
    cout << "Medallas ganadas: ";
    atleta.medallas = rand() % 6;
    cout << atleta.medallas << endl;
    // Se asigna un número aleatorio de medallas (de 0 a 5).

    return atleta;
}

void ingresar_datos(vector<Atleta>& atletas, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        atletas.push_back(ingresar_datos_atleta());
        cout << endl;
    }
}

void desplegar_datos_atleta(Atleta atleta)
{
    cout << "==========================================" << endl;
    cout << "\t Nombre: " << atleta.nombre << endl;
    cout << "\t Departamento: " << atleta.departamento << endl;
    cout << "\t Deporte practicado: " << atleta.deporte << endl;
    cout << "\t Cantidad de medallas ganadas: " << atleta.medallas << endl;
    cout << "==========================================" << endl;
}

void mostrar_medallero(const vector<Atleta>& lista_atletas)
{
    bool encontrado;
    int total_medallas = 0;

    // Se usa un bucle for para sumar las medallas por departamento.
    for (int i = 0; i < lista_atletas.size(); i++)
    {
        encontrado = false;
        // Al inicio de cada bucle, se asume que el departamento no ha sido contado.
        for (int j = 0; j < i; j++)
        // Se compara el departamento del atleta actual (i) con los departamentos anteriores (j).
        {
            if (strcmp(lista_atletas[i].departamento, lista_atletas[j].departamento) == 0)
            {
                encontrado = true;
                // Si el departamento ya fue encontrado, ya no se hacem más comparaciones.
            }
        }

        // Si el departamento no fue encontrado, se agrega al medallero.
        if (encontrado == false)
        {
            total_medallas = 0;
            // Se reinicia la variable total_medallas para cada nuevo departamento.
            for (int k = 0; k < lista_atletas.size(); k++)
            {
                if (strcmp(lista_atletas[i].departamento, lista_atletas[k].departamento) == 0)
                // Si se encuentra un atleta que pertenece al mismo departamento que el actual (i), se suma sus medallas.
                {
                    total_medallas = total_medallas + lista_atletas[k].medallas;
                }
            }

            cout << lista_atletas[i].departamento << ": " << total_medallas << " medallas" << endl;
        }
    }
}