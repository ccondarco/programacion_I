// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 28/08/2025
// Número de ejercicio: 22

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int primer_numero = 0;
    int segundo_numero = 0;
    cout << "Ingresar primer número: ";
    cin >> primer_numero;
    cout << "Ingresar segundo número: ";
    cin >> segundo_numero;
    if (primer_numero != 0 && segundo_numero != 0)
    // Para evitar las divisiones por cero, se verifica que ninguno de los dos números sea cero.
    {
        if (primer_numero % segundo_numero == 0)
        {
            cout << primer_numero << " es múltiplo de " << segundo_numero << endl;
        }
        else
        {
            cout << primer_numero << " no es múltiplo de " << segundo_numero << endl;
        }        
        if (segundo_numero % primer_numero == 0)
        {
            cout << segundo_numero << " es múltiplo de " << primer_numero << endl;
        }
        else
        {
            cout << segundo_numero << " no es múltiplo de " << primer_numero << endl;
        }
    }
    else
    {

        cout << "No se puede verificar múltiplos si uno de los números es cero." << endl;
    }
    
    return 0;
}