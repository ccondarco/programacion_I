// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 03/09/2025
// Número de ejercicio: 24

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int opcion;
    do
    {
        cout << "1. Opción 1" << endl;
        cout << "2. Opción 2" << endl;
        cout << "3. Opción 3" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        if (opcion >= 0 && opcion <= 3)
        // Se verifica si la opción está dentro del rango válido (0 a 3).
        {
            if (opcion == 1)
            {
                cout << "Se eligió la opción 1." << endl << endl;
            }
            if (opcion == 2)
            {
                cout << "Se eligió la opción 2." << endl << endl;
            }
            if (opcion == 3)
            {
                cout << "Se eligió la opción 3." << endl << endl;
            }
            if (opcion == 0)
            {
                cout << "Se eligió salir del sistema." << endl;
            }
        }
        else
        {
            cout << "Opción inválida. Seleccionar una opción del menú." << endl << endl;
        }
    } while(opcion != 0);
    // El bucle continúa hasta que se elija salir (opción 0).
    return 0;
}
