// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 13/11/2025
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

struct struct_estudiante
{
    char ci[10];
    char nombres[30];
    char apellidos[30];
};

struct struct_notas
{
    char ci[10];
    char materia[30];
    int nota;
};

void desplegar_menu_opciones(string nombre_archivo_estudiantes, string nombre_archivo_notas);
void ingresar_datos_estudiante(string nombre_archivo_estudiantes);
bool existe_estudiante(string nombre_archivo_estudiantes, char CI[]);
void ingresar_notas(string nombre_archivo_notas, string nombre_archivo_estudiantes);
bool existe_nota(string nombre_archivo_notas, char CI[], char materia[]);
void reporte(string nombre_archivo_notas, string nombre_archivo_estudiantes);

int main()
{
    system("chcp 65001");
    system("cls");

    string nombre_archivo_estudiantes = "Ejercicio_11_01_Estudiantes.bin";
    string nombre_archivo_notas = "Ejercicio_11_01_Notas.bin";

    desplegar_menu_opciones(nombre_archivo_estudiantes, nombre_archivo_notas);

    return 0;
}

void desplegar_menu_opciones(string nombre_archivo_estudiantes, string nombre_archivo_notas)
{
   int opcion;
   do
   {
        system("cls");
        cout << "============== MENÚ DE OPCIONES ==============" << endl;
        cout << "\t1. Ingreso de datos estudiantes" << endl;
        cout << "\t2. Ingreso de materias y notas" << endl;
        cout << "\t3. Reporte de estudiantes y notas ingresadas" << endl;
        cout << "\t0. Salir" << endl;
        cout << endl;
        cout << "Seleccionar opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            ingresar_datos_estudiante(nombre_archivo_estudiantes);
            break;
        case 2:
            ingresar_notas(nombre_archivo_notas, nombre_archivo_estudiantes);
            break;
        case 3:
            reporte(nombre_archivo_notas, nombre_archivo_estudiantes);
            break;
        default:
            if (opcion != 0)
                {
                    cout << "Opción inválida." << endl;
                    system("pause");
                }
            break;
        }
        
   } while (opcion != 0);
   system("cls");
    
}

void ingresar_datos_estudiante(string nombre_archivo_estudiantes)
{
    struct_estudiante estudiante;
    fstream archivo_estudiantes;

    archivo_estudiantes.open(nombre_archivo_estudiantes, ios::binary | ios::in | ios::out | ios::app);
    // Se abre el archivo binario en modo lectura, escritura y append.
    
    cin.ignore();
    cout << "Ingresar CI: ";
    cin.getline(estudiante.ci, 10);

    if (archivo_estudiantes.good())
    // Se verifica si el archivo se abrió correctamente.
    {
        if (existe_estudiante(nombre_archivo_estudiantes, estudiante.ci))
        // Se verifica si el estudiante ya existe.
        {
            cout << "Inválido. El estudiante ya existe." << endl;
            system("pause");
            return;
        }
        
        cout << "Ingresar nombres: ";
        cin.getline(estudiante.nombres, 30);
        cout << "Ingresar apellidos: ";
        cin.getline(estudiante.apellidos, 30);
        
        archivo_estudiantes.write((char*)&estudiante, sizeof(struct_estudiante));
        // Se escriben los datos en el archivo binario.
        system("pause");
    }
    else
    {
        cout << "No se pudo ingresar los datos." << endl;
    }
    archivo_estudiantes.close();
}

bool existe_estudiante(string nombre_archivo_estudiantes, char CI[])
{
    ifstream archivo_estudiante;
    struct_estudiante estudiante;

    archivo_estudiante.open(nombre_archivo_estudiantes, ios::binary);
    if (!archivo_estudiante.good())
    {
        return false;
        // Si no se pudo abrir el archivo, se asume que no existe.
    }
    while (archivo_estudiante.read((char*)&estudiante, sizeof(struct_estudiante)))
    {
        if (strcmp(estudiante.ci, CI) == 0)
        // Se comparan los CIs.
        {
            return true;
            // El estudiante existe.
        }
    }
    return false;
    // No se encontró.
}

void ingresar_notas(string nombre_archivo_notas, string nombre_archivo_estudiantes)
{
    struct_notas notas;
    fstream archivo_notas;

    archivo_notas.open(nombre_archivo_notas, ios::binary | ios::in | ios::out | ios::app);
    
    cin.ignore();
    cout << "Ingresar CI: ";
    cin.getline(notas.ci, 10);

    if (archivo_notas.good())
    {
        if (!existe_estudiante(nombre_archivo_estudiantes, notas.ci))
        {
            cout << "Inválido. El estudiante no existe." << endl;
            system("pause");
            return;
        }
        
        cout << "Ingresar materia: ";
        cin.getline(notas.materia, 30);

        if (existe_nota(nombre_archivo_notas, notas.ci, notas.materia))
        // Se verifica si ya existe una nota para esa materia.
        {
            cout << "Inválido. La materia ya tiene una nota registrada." << endl;
            system("pause");
            return;
        }

        cout << "Ingresar nota: ";
        cin >> notas.nota;
        
        archivo_notas.write((char*)&notas, sizeof(struct_notas));
        system("pause");
    }
    else
    {
        cout << "No se pudo ingresar los datos." << endl;
    }
    archivo_notas.close();
}

bool existe_nota(string nombre_archivo_notas, char CI[], char materia[])
{
    ifstream archivo_notas;
    struct_notas nota;

    archivo_notas.open(nombre_archivo_notas, ios::binary);
    if (!archivo_notas.good())
    {
        return false;
    }
    while (archivo_notas.read((char*)&nota, sizeof(struct_notas)))
    {
        if (strcmp(nota.ci, CI) == 0 && strcmp(nota.materia, materia) == 0 )
        {
            return true;
        }
    }
    return false;
}

void reporte(string nombre_archivo_notas, string nombre_archivo_estudiantes)
{
    struct_estudiante estudiante;
    struct_notas notas;
    ifstream archivo_estudiantes;
    ifstream archivo_notas;
    bool tiene_notas;

    archivo_estudiantes.open(nombre_archivo_estudiantes, ios::binary);
    archivo_notas.open(nombre_archivo_notas, ios::binary);

    while (archivo_estudiantes.read((char*)&estudiante, sizeof(struct_estudiante)))
    {
        cout << "CI: " << estudiante.ci << endl;
        cout << "Nombre: " << estudiante.nombres << " " << estudiante.apellidos << endl;
        cout << "Notas: " << endl;

        tiene_notas = false;

        archivo_notas.clear();
        // Se reinician todas las banderas.
        archivo_notas.seekg(0);
        // Se mueve el puntero al inicio del archivo.

        while (archivo_notas.read((char*)&notas, sizeof(struct_notas)))
        {
            if (strcmp(notas.ci, estudiante.ci) == 0)
            // Sólo se muestra el estudiante buscado.
            {
                cout << "   - " << notas.materia << ": " << notas.nota << endl;
                tiene_notas = true;
            }
        }

        if (!tiene_notas)
            cout << "(Sin notas)" << endl;

            cout << "-----------------------------------\n";
    }
    system("pause");
}