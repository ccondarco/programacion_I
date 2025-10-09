// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/10/2025
// Número de ejercicio: 12

#include <iostream>
#include <string>

using namespace std;

bool es_palindromo(string texto);
string normalizar_texto(string texto);

int main()
{
    system("chcp 65001");
    system("cls");
    
    string texto;

    cout << "Ingresar texto: ";
    getline(cin, texto);

    if (es_palindromo(texto) == true)
    {
        cout << "El texto es palíndromo." << endl;
    }
    else
    {
        cout << "El texto no es palíndromo." << endl;
    }

    return 0;
}

string igualar_texto(string texto)
// La función elimina caracteres no alfabéticos y convierte a minúsculas.
{
    string texto_igualado = "";

    for (int i = 0; i < texto.size(); i++)
    {
        char caracter_actual = texto[i];

        // Sólo se agrega el carácter si es alfabético y se convierte a minúscula.
        if ((caracter_actual >= 'a' && caracter_actual <= 'z') || (caracter_actual >= 'A' && caracter_actual <= 'Z'))
        {
            if (caracter_actual >= 'A' && caracter_actual <= 'Z')
            {
                caracter_actual = caracter_actual + ('a' - 'A');
            }
            texto_igualado = texto_igualado + caracter_actual;
        }
    }

    return texto_igualado;
}

bool es_palindromo(string texto)
{
    string texto_igualado = igualar_texto(texto);
    int longitud = texto_igualado.size();
    bool es_palindromo = true;

    for (int i = 0; i < longitud / 2; i++)
    {
        if (texto_igualado[i] != texto_igualado[longitud - 1 - i])
        {
            return false;
        }
    }

    return es_palindromo;
}