// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/10/2025
// Número de ejercicio: 10

#include <iostream>
#include <string>

using namespace std;

string eliminar_digitos(string texto);

int main()
{
    system("chcp 65001");
    system("cls");

    string texto;
    string resultado;

    cout << "Ingresar texto: ";
    getline(cin, texto);

    resultado = eliminar_digitos(texto);

    cout << "Cadena sin dígitos: " << resultado << endl;

    return 0;
}

string eliminar_digitos(string texto)
{
    string resultado = "";

    for (int i = 0; i < texto.size(); i++)
    {
        // Si el carácter no es un dígito, se agrega al resultado.
        if (texto[i] < '0' || texto[i] > '9')
        {
            resultado = resultado + texto[i];
        }
    }

    return resultado;
}
