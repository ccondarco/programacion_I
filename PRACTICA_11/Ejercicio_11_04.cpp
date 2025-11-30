// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 23/11/2025
// Número de ejercicio: 4

#include <iostream>
#include <fstream>

using namespace std;

struct Datos_estudiante
{
    int carnet;
    char nombres[50];
    char apellidos[50];
    char materia[20];
    int paralelo;
    bool eliminado;
    float nota1;
    float nota2;
    float nota3;
    float nota_habilitacion;
};

void menu_opciones(string nombre_archivo);
void adicionar_estudiante(string nombre_archivo);
void listado_estudiantes_habilitados(string nombre_archivo);
void eliminar_estudiante(string nombre_archivo);
void adicionar_notas_habilitacion(string nombre_archivo);

int main()
{
    system("chcp 65001");
    system("cls");

    string nombre_archivo = "Ejercicio_11_04_Estudiantes.bin";

    menu_opciones(nombre_archivo);

    return 0;
}

void menu_opciones(string nombre_archivo)
{
    int opcion;

    do
    {
        system("cls");
        cout << "======= MENÚ DE OPCIONES =======" << endl;
        cout << "1. Adicionar estudiante" << endl;
        cout << "2. Listado de estudiantes habilitados" << endl;
        cout << "3. Eliminar estudiante" << endl;
        cout << "4. Adicionar notas de habilitación" << endl;
        cout << "0. Salir" << endl;
        cout << endl;
        cout << "Seleccionar opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            adicionar_estudiante(nombre_archivo);
            break;
        
        case 2:
            listado_estudiantes_habilitados(nombre_archivo);
            break;
        
        case 3:
            eliminar_estudiante(nombre_archivo);
            break;

        case 4:
            adicionar_notas_habilitacion(nombre_archivo);
            break;

        default:
            if (opcion != 0)
            {
                cout << "Opción inválida." << endl;
            }
            break;
        }
    } while (opcion != 0);
}

void adicionar_estudiante(string nombre_archivo)
{
    Datos_estudiante estudiante;
    ofstream archivo_estudiantes;

    archivo_estudiantes.open(nombre_archivo, ios::binary | ios::app);
    if (archivo_estudiantes.good())
    {
        cout << "Ingresar carnet de estudiante: ";
        cin >> estudiante.carnet;
        cin.ignore();
        cout << "Ingresar nombres: ";
        cin.getline(estudiante.nombres, 50);
        cout << "Ingresar apellidos: ";
        cin.getline(estudiante.apellidos, 50);
        cout << "Ingresar materia: ";
        cin.getline(estudiante.materia, 20);
        cout << "Ingresar paralelo: ";
        cin >> estudiante.paralelo;
        estudiante.eliminado = false;
        // Inicialmente el estudiante no está eliminado.
        cout << endl;
        archivo_estudiantes.write((char*)&estudiante, sizeof(Datos_estudiante));
        cout << "Estudiante adicionado correctamente" << endl;
        system("pause");
    }
    else
    {
        cout << "No se pudo adicionar datos." << endl;
        system("pause");
    }
    archivo_estudiantes.close();
}

void listado_estudiantes_habilitados(string nombre_archivo)
{
    Datos_estudiante estudiante;
    ifstream archivo_estudiantes;
    string estado;

    archivo_estudiantes.open(nombre_archivo, ios::binary | ios::in);
    if (archivo_estudiantes.good())
    {
        cout << "LISTADO DE ESTUDIANTES HABILITADOS" << endl;
        cout << "CARNET \t NOMBRES \tAPELLIDOS \tMATERIA \tPARALELO \tNOTA HABILITACIÓN \tESTADO" << endl;
        while (archivo_estudiantes.read((char*)&estudiante, sizeof(Datos_estudiante)))
        {
            if (!estudiante.eliminado)
            {
                if (estudiante.nota1 >= 60 && estudiante.nota2 >= 60 && estudiante.nota3 >= 60 && estudiante.nota_habilitacion >= 60)
                // Se determina el estado del estudiante según sus notas.
                {
                    estado = "HABILITADO";
                }
                else
                {
                    if (estudiante.nota1 < 60 && estudiante.nota2 < 60 && estudiante.nota3 < 60)
                    {
                        estado = "NO HABILITADO.";
                    }
                    else
                    {
                        estado = "NO HABILITADO. TIENE UNA NOTA MENOR A 60.";
                    }
                }

                cout << estudiante.carnet << "\t" << estudiante.nombres << "\t" << estudiante.apellidos << "\t" << estudiante.materia << "\t" << estudiante.paralelo << "\t" << estudiante.nota_habilitacion << "\t" << estado << endl;
            }
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo para listar estudiantes." << endl;
    }
    archivo_estudiantes.close();
    system("pause");
}

void eliminar_estudiante(string nombre_archivo)
{
    Datos_estudiante estudiante;
    fstream archivo_estudiantes;
    int carnet_a_buscar;
    bool estudiante_encontrado = false;

    cout << "Ingresar carnet de estudiante a eliminar: ";
    cin >> carnet_a_buscar;

    archivo_estudiantes.open(nombre_archivo, ios::binary | ios::in | ios::out);
    // Se abre el archivo en modo lectura/escritura.
    if (archivo_estudiantes.good())
    {
        while (archivo_estudiantes.read((char*)&estudiante, sizeof (Datos_estudiante)) && !estudiante_encontrado)
        {
            if (carnet_a_buscar == estudiante.carnet && !estudiante.eliminado)
            // Se verifica si el estudiante coincide y no está eliminado.
            {
                cout << "Estudiante eliminado" << endl;
                cout << "---------------------------" << endl;
                cout << "Carnet de estudiante: " << estudiante.carnet << endl;
                cout << "Nombres: " << estudiante.nombres << endl;
                cout << "Apellidos: " << estudiante.apellidos << endl;
                cout << "Materia: " << estudiante.materia << endl;
                cout << "Paralelo: " << estudiante.paralelo << endl;
                cout << "---------------------------" << endl;
                cout << endl;
                estudiante_encontrado = true;

                archivo_estudiantes.seekp(-sizeof(Datos_estudiante), ios::cur);
                // Se retrocede el puntero y se marca como eliminado.
                estudiante.eliminado = true;
                archivo_estudiantes.write((char*)&estudiante, sizeof(Datos_estudiante));
                // Se guarda la modificación.

                cout << "Estudiante eliminado correctamente." << endl;
            }
        }
        if (!estudiante_encontrado)
        {
            cout << "El estudiante no pudo ser encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo para eliminar estudiante." << endl;
        system("pause");
    }
    archivo_estudiantes.close();    
    
    system("pause");
}

void adicionar_notas_habilitacion(string nombre_archivo)
{
    Datos_estudiante estudiante;
    fstream archivo_estudiantes;
    int carnet_a_buscar;
    bool estudiante_encontrado = false;

    cout << "Ingresar carnet de estudiante para adicionar notas: ";
    cin >> carnet_a_buscar;

    archivo_estudiantes.open(nombre_archivo, ios::binary | ios::in | ios::out);
    if (archivo_estudiantes.good())
    {
        while (archivo_estudiantes.read((char*)&estudiante, sizeof (Datos_estudiante)) && !estudiante_encontrado)
        {
            if (carnet_a_buscar == estudiante.carnet && !estudiante.eliminado)
            {
                cout << "Estudiante encontrado" << endl;
                cout << "---------------------------" << endl;
                cout << "Carnet de estudiante: " << estudiante.carnet << endl;
                cout << "Nombres: " << estudiante.nombres << endl;
                cout << "Apellidos: " << estudiante.apellidos << endl;
                cout << "Materia: " << estudiante.materia << endl;
                cout << "Paralelo: " << estudiante.paralelo << endl;
                cout << "---------------------------" << endl;
                cout << endl;
                estudiante_encontrado = true;

                archivo_estudiantes.seekp(-sizeof(Datos_estudiante), ios::cur);
                // Se retrocede el puntero para actualizar notas.
                
                cout << "Ingresar primera nota parcial: ";
                cin >> estudiante.nota1;
                cout << "Ingresar segunda nota parcial: ";
                cin >> estudiante.nota2;
                cout << "Ingresar tercera nota parcial: ";
                cin >> estudiante.nota3;
                estudiante.nota_habilitacion = (estudiante.nota1 + estudiante.nota2 + estudiante.nota3) / 3.0;
                archivo_estudiantes.write((char*)&estudiante, sizeof(Datos_estudiante));
                
                cout << "Notas registradas correctamente." << endl;
                cout << "Promedio de habilitación: " << estudiante.nota_habilitacion << endl;
            }
        }
        if (!estudiante_encontrado)
        {
            cout << "El estudiante no pudo ser encontrado." << endl;
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo para adicionar notas." << endl;
        system("pause");
    }
    archivo_estudiantes.close();    
    
    system("pause");
}