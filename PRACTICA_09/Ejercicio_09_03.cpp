// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 02/11/2025
// Número de ejercicio: 3

#include <iostream>
#include <vector>
using namespace std;

struct estudiante_programacion
{
    int cedula;
    char nombre[50];
    char apellidos[50];
    int edad;
    char profesion[50];
    char lugar_nacimiento[50];
    char direccion[50];
    int telefono;
};

estudiante_programacion ingresar_datos_estudiante();
void ingresar_datos(vector<estudiante_programacion>& estudiantes, int cantidad);
void desplegar_datos_estudiante(estudiante_programacion estudiante);
void mostrar_lista_estudiantes(vector<estudiante_programacion> estudiantes, int cantidad);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_estudiantes;
    vector<estudiante_programacion> estudiantes_programacion_I;

    cout << "Ingresar cantidad de estudiantes: ";
    cin >> cantidad_estudiantes;

    ingresar_datos(estudiantes_programacion_I, cantidad_estudiantes);

    cout << "LISTA DE ESTUDIANTES - PROGRAMACIÓN I" << endl;
    mostrar_lista_estudiantes(estudiantes_programacion_I, cantidad_estudiantes);

    return 0;
}

estudiante_programacion ingresar_datos_estudiante()
{
    estudiante_programacion estudiante;

    cout << "Ingresar cédula de identidad: ";
    cin >> estudiante.cedula;
    cin.ignore();
    cout << "Ingresar nombre: ";
    cin.getline(estudiante.nombre, 50);
    cout << "Ingresar apellidos: ";
    cin.getline(estudiante.apellidos, 50);
    cout << "Ingresar edad: ";
    cin >> estudiante.edad;
    cin.ignore();
    cout << "Ingresar profesión: ";
    cin.getline(estudiante.profesion, 50);
    cout << "Ingresar lugar de nacimiento: ";
    cin.getline(estudiante.lugar_nacimiento, 50);
    cout << "Ingresar dirección: ";
    cin.getline(estudiante.direccion, 50);
    cout << "Ingresar teléfono: ";
    cin >> estudiante.telefono;

    return estudiante;
}

void ingresar_datos(vector<estudiante_programacion>& estudiantes, int cantidad)
// Se recibe el vector por referencia para que los datos se almacenen en la lista original.
{
    for (int i = 0; i < cantidad; i++)
    {
        estudiantes.push_back(ingresar_datos_estudiante());
        cout << endl;
    }
}

void desplegar_datos_estudiante(estudiante_programacion estudiante)
{
    cout << "==========================================" << endl;
    cout << "\t Cédula de identidad: " << estudiante.cedula << endl;
    cout << "\t Nombre: " << estudiante.nombre << endl;
    cout << "\t Apellidos: " << estudiante.apellidos << endl;
    cout << "\t Edad: " << estudiante.edad << endl;
    cout << "\t Profesión: " << estudiante.profesion << endl;
    cout << "\t Lugar de nacimiento: " << estudiante.lugar_nacimiento << endl;
    cout << "\t Dirección: " << estudiante.direccion << endl;
    cout << "\t Teléfono: " << estudiante.telefono << endl;
    cout << "==========================================" << endl;
}

void mostrar_lista_estudiantes(vector<estudiante_programacion> estudiantes, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    // Se recorre todo el vector de estudiantes para mostrar la información de cada uno.
    {
        desplegar_datos_estudiante(estudiantes[i]);
    }
}