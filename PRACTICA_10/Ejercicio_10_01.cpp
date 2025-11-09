// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 L.P.
// Carrera del estudiante: Diseño Digital
// Fecha creación: 07/11/2025
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void ingresar_nombres(vector<string>& nombres, int cantidad);
void crear_archivo_txt(vector<string> nombres);
void leer_archivo_txt();

int main()
{
    system("chcp 65001");
    system("cls");

    vector<string> nombres;
    int cantidad_nombres;

    cout << "Ingresar cantidad de nombres que se desea registrar: ";
    cin >> cantidad_nombres;
    cin.ignore();

    ingresar_nombres(nombres, cantidad_nombres);
    crear_archivo_txt(nombres);
    cout << endl;
    leer_archivo_txt();

    return 0;
}

void ingresar_nombres(vector<string>& nombres, int cantidad)
{
    string nombre;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Ingresar nombre " << i + 1 << ": ";
        getline(cin, nombre);
        nombres.push_back(nombre);
    }
}

void crear_archivo_txt(vector<string> nombres)
{
    ofstream archivo_nombres;
    archivo_nombres.open("NOMBRES.TXT");
    // Se crea el archivo txt.

    archivo_nombres << "NOMBRES REGISTRADOS" << endl;
    for (int i = 0; i < nombres.size(); i++)
    {
        archivo_nombres << "\t" << i + 1 << ". " << nombres[i] << endl;
    }
    archivo_nombres.close();
    // Siempre se debe cerrar el archivo.
}

void leer_archivo_txt()
{
    ifstream archivo_nombres;
    string texto;
    // Se crea una variable string para poder copiar el texto del archivo al programa.

    archivo_nombres.open("NOMBRES.TXT");
    // Se abre el archivo para su lectura.
    while (getline(archivo_nombres, texto))
    {
        cout << texto << endl;
    }
    archivo_nombres.close();
}