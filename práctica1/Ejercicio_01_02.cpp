// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 22/08/2025
// Número de ejercicio: 2

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int variable1 = 0;
    int variable2 = 0;
    cout << "Variable 1: " << variable1 << endl;
    cout << "Variable 2: " << variable2 << endl;
    cout << "Ingresar nuevo valor para variable 1: ";
    cin >> variable1;
    cout << "Ingresar nuevo valor para variable 2: ";
    cin >> variable2;
    cout << "Variable 1: " << variable1 << endl;
    cout << "Variable 2: " << variable2 << endl;
    // Se utiliza "endl" para dividir las oraciones en diferentes líneas. Sino, la consola las muestra todas juntas.
    return 0;
}