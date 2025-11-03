// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 02/11/2025
// Número de ejercicio: 4

#include <iostream>
#include <vector>

using namespace std;

struct Empleado
{
    char nombre[50];
    char genero[10];
    float salario;
};

Empleado ingresar_datos_empleado();
void ingresar_datos(vector<Empleado>& empleados, int cantidad);
void desplegar_datos_empleado(Empleado empleado);
void mostrar_menor_mayor_salario(vector<Empleado> empleados);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_empleados;
    vector<Empleado> lista_empleados;

    cout << "Ingresar cantidad de empleados: ";
    cin >> cantidad_empleados;
    
    ingresar_datos(lista_empleados, cantidad_empleados);
    mostrar_menor_mayor_salario(lista_empleados);

    return 0;
}

Empleado ingresar_datos_empleado()
{
    Empleado empleado;

    cin.ignore();
    cout << "Ingresar nombre: ";
    cin.getline(empleado.nombre, 50);
    cout << "Ingresar género: ";
    cin.getline(empleado.genero, 50);
    cout << "Ingresar salario: ";
    cin >> empleado.salario;

    return empleado;
}

void ingresar_datos(vector<Empleado>& empleados, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        empleados.push_back(ingresar_datos_empleado());
        cout << endl;
    }
}

void desplegar_datos_empleado(Empleado empleado)
{
    cout << "==========================================" << endl;
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Género: " << empleado.genero << endl;
    cout << "Salario: Bs." << empleado.salario << endl;
    cout << "==========================================" << endl;
}

void mostrar_menor_mayor_salario(vector<Empleado> empleados)
{
    float menor_salario = 1000000;
    float mayor_salario = 0;
    // Se inicializan dos variables flotantes para comparar salarios y detectar el menor y el mayor salario.
    Empleado empleado_menor_salario;
    Empleado empleado_mayor_salario;
    // Se inicializan dos variables para poder guardar las estructuras de los dos empleados con menor y mayor salario.

    for (int i = 0; i < empleados.size(); i++)
    {
        if (empleados[i].salario < menor_salario)
        {
            menor_salario = empleados[i].salario;
            empleado_menor_salario = empleados[i];
        }
        else
        {
            if (empleados[i].salario > mayor_salario)
            {
                mayor_salario = empleados[i].salario;
                empleado_mayor_salario = empleados[i];
            }
        }
        // Las condiciones permiten guardar los datos en una de las variables inicializadas dentro de la fucnión.
    }
    
    cout << "EMPLEADO CON MENOR SALARIO" << endl;
    desplegar_datos_empleado(empleado_menor_salario);
    cout << endl;

    cout << "EMPLEADO CON MAYOR SALARIO" << endl;
    desplegar_datos_empleado(empleado_mayor_salario);
}