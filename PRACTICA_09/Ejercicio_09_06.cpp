// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/11/2025
// Número de ejercicio: 6

#include <iostream>
#include <vector>

using namespace std;

struct Empleado
{
    char nombre[50];
    int ID;
    float sueldo;
    int antiguedad;
};

Empleado ingresar_datos_empleado();
void ingresar_datos(vector<Empleado>& empleados, int cantidad);
void desplegar_datos_empleado(Empleado empleado);
void mostrar_lista_sueldos_mayores(vector<Empleado> empleados, float campo_ingresado);
double calcular_promedio_antiguedad(vector<Empleado> empleados);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_empleados;
    vector<Empleado> lista_empleados;
    float sueldo;
    double promedio_antiguedades;

    cout << "Ingresar cantidad de empleados: ";
    cin >> cantidad_empleados;
    
    ingresar_datos(lista_empleados, cantidad_empleados);

    cout << "Ingresar monto de sueldo a comparar: ";
    cin >> sueldo;
    cout << endl;
    cout << "EMPLEADOS CON SUELDO MAYOR A BS." << sueldo << endl;
    mostrar_lista_sueldos_mayores(lista_empleados, sueldo);
    cout << endl;

    promedio_antiguedades = calcular_promedio_antiguedad(lista_empleados);
    cout << "El promedio de antigüedad de todos los empleados es de " << promedio_antiguedades << " años." << endl;

    return 0;
}

Empleado ingresar_datos_empleado()
{
    Empleado empleado;

    cin.ignore();
    cout << "Ingresar nombre: ";
    cin.getline(empleado.nombre, 50);
    cout << "Ingresar ID: ";
    cin >> empleado.ID;
    cout << "Ingresar sueldo: ";
    cin >> empleado.sueldo;
    cout << "Ingresar antigüedad (en años): ";
    cin >> empleado.antiguedad;

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
    cout << "ID: " << empleado.ID << endl;
    cout << "Sueldo: Bs." << empleado.sueldo << endl;
    cout << "Años de antigüedad: " << empleado.antiguedad << endl;
    cout << "==========================================" << endl;
}

void mostrar_lista_sueldos_mayores(vector<Empleado> empleados, float campo_ingresado)
{
    for (int i = 0; i < empleados.size(); i++)
    {
        if (empleados[i].sueldo > campo_ingresado)
        // Si el sueldo del empleado es mayor que el monto ingresado, se muestra su información.
        {
            desplegar_datos_empleado(empleados[i]);
        }
    }
}

double calcular_promedio_antiguedad(vector<Empleado> empleados)
{
    double suma_antiguedades = 0;
    double promedio_antiguedades;

    for (int i = 0; i < empleados.size(); i++)
    {
        suma_antiguedades = suma_antiguedades + empleados[i].antiguedad;
    }
    
    promedio_antiguedades = suma_antiguedades / empleados.size();

    return promedio_antiguedades;
}