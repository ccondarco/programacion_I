// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/10/2025
// Número de ejercicio: 14

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> contar_vocales(string texto);

int main()
{
    system("chcp 65001");
    system("cls");
    
    string texto;
    vector<int> cantidad_vocales;
    vector<char> vocales;

    cout << "Ingresar texto: ";
    getline(cin, texto);

    cantidad_vocales = contar_vocales(texto);
    vocales = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++)
    {
        cout << vocales[i] << ": " << cantidad_vocales[i] << endl;
    }

    return 0;
}

vector<int> contar_vocales(string texto)
{
    vector<int> conteo_vocales(5, 0);

    for (int i = 0; i < texto.size(); i++)
    {
        // Se revisa si el caracter es una vocal en minúscula o mayúscula.
        if (texto[i] == 'a' || texto[i] == 'A')
        {
            conteo_vocales[0] = conteo_vocales[0] + 1;
        }
        else
        {
            if (texto[i] == 'e' || texto[i] == 'E')
            {
                conteo_vocales[1] = conteo_vocales[1] + 1;
            }
            else
            {
                if (texto[i] == 'i' || texto[i] == 'I')
                {
                    conteo_vocales[2] = conteo_vocales[2] + 1;
                }
                else
                {
                    if (texto[i] == 'o' || texto[i] == 'O')
                    {
                        conteo_vocales[3] = conteo_vocales[3] + 1;
                    }
                    else
                    {
                        if (texto[i] == 'u' || texto[i] == 'U')
                        {
                            conteo_vocales[4] = conteo_vocales[4] + 1;
                        }
                    }
                }
            }
        }
    }

    return conteo_vocales;
}
