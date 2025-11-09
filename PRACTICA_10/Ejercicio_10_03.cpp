// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 08/11/2025
// Número de ejercicio: 3

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Datos_estudiante
{
    char nombre[50];
    int edad;
    float promedio;
};

Datos_estudiante ingresar_datos_estudiante();
void ingresar_datos(vector<Datos_estudiante>& estudiantes, int cantidad);
void desplegar_datos_estudiante(Datos_estudiante estudiante);
void crear_archivo_txt(vector<Datos_estudiante> estudiantes);
void leer_archivo_txt();

int main()
{
    system("chcp 65001");
    system("cls");
    
    int cantidad_estudiantes;
    vector<Datos_estudiante> estudiantes;

    cout << "Ingresar cantidad de estudiantes: ";
    cin >> cantidad_estudiantes;

    ingresar_datos(estudiantes, cantidad_estudiantes);
    crear_archivo_txt(estudiantes);
    leer_archivo_txt();
    
    return 0;
}

void numeros_aleatorios(int minimo, int maximo)
{
    int numero_aleatorio;

    numero_aleatorio = (rand() % (maximo - minimo + 1)) + minimo;
}

Datos_estudiante ingresar_datos_estudiante()
{
    Datos_estudiante estudiante;

    cin.ignore();
    cout << "Ingresar nombre: ";
    cin.getline(estudiante.nombre, 50);
    cout << "Ingresar edad: ";
    cin >> estudiante.edad;
    cout << "Ingresar promedio (0-10): ";
    cin >> estudiante.promedio;

    return estudiante;
}

void ingresar_datos(vector<Datos_estudiante>& estudiantes, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        estudiantes.push_back(ingresar_datos_estudiante());
        cout << endl;
    }
}

void desplegar_datos_estudiante(vector<Datos_estudiante> estudiantes)
{
    for (int i = 0; i < estudiantes.size(); i++)
    {
        cout << "=======================================" << endl;
        cout << "\t Nombre del estudiante: " << estudiantes[i].nombre << endl;
        cout << "\t Edad: " << estudiantes[i].edad << endl;
        cout << "\t Promedio de notas recibidas: " << estudiantes[i].promedio << endl;
        cout << "=======================================" << endl;
    }
    
    
}

void crear_archivo_txt(vector<Datos_estudiante> estudiantes)
{
    ofstream archivo_estudiantes;
    archivo_estudiantes.open("ESTUDIANTES.TXT");
    
    archivo_estudiantes << "ESTUDIANTES REGISTRADOS" << endl;
    for (int i = 0; i < estudiantes.size(); i++)
    {
        archivo_estudiantes << "================================================" << endl;
        archivo_estudiantes << "\t Nombre del estudiante: " << estudiantes[i].nombre << endl;
        archivo_estudiantes << "\t Edad: " << estudiantes[i].edad << endl;
        archivo_estudiantes << "\t Promedio de notas recibidas: " << estudiantes[i].promedio << endl;
        archivo_estudiantes << "================================================" << endl;
    }

    archivo_estudiantes.close();
}

void leer_archivo_txt()
{
    ifstream archivo_estudiantes;
    string texto;

    archivo_estudiantes.open("ESTUDIANTES.TXT");
    while (getline(archivo_estudiantes, texto))
    {
        cout << texto << endl;
    }
    archivo_estudiantes.close();
}