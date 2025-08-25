// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 24/08/2025
// Número de ejercicio: 14

#include <iostream>
using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int numero = 0;
    string asteriscos = "*";
    cout << "Ingresar número: ";
    cin >> numero;
    for (int i=1; i<=numero; i++)
    // El primer bucle controla la cantidad de filas que habrá.
    {
        for (int j=1; j<=i; j++)
        // El segundo bucle imprime la cantidad de asteriscos correspondientes a cada fila.
        {
            cout << "*";
        }
        cout << endl;
        // Se utiliza el salto de línea al terminar cada fila.
    }
    return 0;
}

