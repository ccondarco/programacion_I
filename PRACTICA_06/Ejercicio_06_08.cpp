// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/10/2025
// Número de ejercicio: 8

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

string validar_correo(string correo);

int main()
{
    system("chcp 65001");
    system("cls");

    string correo;
    string validacion;

    cout << "Ingresar correo: ";
    getline(cin, correo);

    validacion = validar_correo(correo);
    cout << validacion << endl;

    return 0;
}

string validar_correo(string correo)
{
    int contador_arroba = 0;
    bool tiene_punto = false;

    for (int i = 0; i < correo.size(); i++)
    {
        if (correo[i] == '@')
        {
            contador_arroba = contador_arroba + 1;
        }
        if (contador_arroba == 1 && correo[i] == '.')
        // Si se encuentra un punto después del primer '@', se marca tiene_punto como verdadero.
        {
            tiene_punto = true;
        }
    }
    
    if (contador_arroba == 1 && tiene_punto == true)
    {
        return "Correo electrónico válido.";
    }
    else
    {
        return "Correo electrónico inválido.";
    }
}