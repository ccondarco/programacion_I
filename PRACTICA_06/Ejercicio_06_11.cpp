// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/10/2025
// Número de ejercicio: 11

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> dividir_en_tokens(string& texto, char delimitador);
void imprimir_tokens(vector<string>& tokens);

int main()
{
    system("chcp 65001");
    system("cls");

    string texto;
    char delimitador;
    vector<string> tokens;

    cout << "Ingresar texto: ";
    getline(cin, texto);

    cout << "Ingresar delimitador: ";
    cin >> delimitador;

    tokens = dividir_en_tokens(texto, delimitador);

    cout << "Tokens obtenidos: " << endl;
    imprimir_tokens(tokens);

    return 0;
}

vector<string> dividir_en_tokens(string& texto, char delimitador)
{
    vector<string> tokens;
    string token = "";

    for (int i = 0; i < texto.size(); i++)
    {
        if (texto[i] != delimitador)
        // Si el carácter no es el delimitador, se agrega al token actual.
        {
            token = token + texto[i];
        }
        else
        {
            if (texto[i] == delimitador && token.size() > 0)
            // Si se encuentra el delimitador y el token no está vacío, se agrega al vector.
            {
            tokens.push_back(token);
            token = "";
            }
        } 
    }

    // Si el último token no está vacío, se agrega al vector.
    if (token.size() > 0)
    {
        tokens.push_back(token);
    }

    return tokens;
}

void imprimir_tokens(vector<string>& tokens)
{
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << endl;
    }
}
