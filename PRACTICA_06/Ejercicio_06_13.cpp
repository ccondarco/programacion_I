// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/10/2025
// Número de ejercicio: 13

#include <iostream>
#include <string>

using namespace std;

string volver_mayusculas(string texto);

int main()
{
    system("chcp 65001");
    system("cls");
    
    string texto;

    cout << "Ingresar texto: ";
    getline(cin, texto);

    string resultado = volver_mayusculas(texto);

    cout << "Texto con primeras letras en mayúsculas: " << resultado << endl;

    return 0;
}

string volver_mayusculas(string texto)
{
    string resultado = "";
    bool es_inicio_palabra = true;
    char caracter_actual;

    for (int i = 0; i < texto.size(); i++)
    {
        caracter_actual = texto[i];

        if (caracter_actual >= 'a' && caracter_actual <= 'z')
        {
            if (es_inicio_palabra == true)
            {
                caracter_actual = caracter_actual - ('a' - 'A');
                es_inicio_palabra = false;
                // Se cambia a false para que las siguientes letras no cambien.
            }
        }

        if (caracter_actual >= 'A' && caracter_actual <= 'Z')
        {
            if (es_inicio_palabra == true)
            {
                es_inicio_palabra = false;
            }
        }

        // Si se encuentra un espacio u otro carácter, se marca que la siguiente letra es el inicio de una palabra.
        if (caracter_actual == ' ' || (caracter_actual < 'A' || caracter_actual > 'Z') && (caracter_actual < 'a' || caracter_actual > 'z'))
        {
            es_inicio_palabra = true;
        }

        // Se añade el carácter actual al resultado.
        resultado = resultado + caracter_actual;
    }

    return resultado;
}
