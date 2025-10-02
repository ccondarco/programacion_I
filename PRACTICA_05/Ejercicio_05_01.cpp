// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Fecha creación: 01/10/2025
// Número de ejercicio: 1
// Problema planteado: Escribir un programa con 6 funciones utilizando vectores para generar voltajes, temperaturas, caracteres alfanuméricos, años, velocidades y distancias, utilizando números aleatorios.

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<double> generar_voltajes();
vector<double> generar_temperaturas();
vector<char> generar_caracteres();
vector<int> generar_anios();
vector<double> generar_velocidades();
vector<double> generar_distancias();
void mostrar_voltajes(vector<double> voltajes);
void mostrar_temperaturas(vector<double> temperaturas);
void mostrar_caracteres (vector<char> caracteres);
void mostrar_anios(vector<int> anios);
void mostrar_velocidades(vector<double> velocidades);
void mostrar_distancias(vector<double> distancias);

int main()
{
    system("chcp 65001");
    system("cls");

    srand(time(0));

    vector<double> voltajes;
    vector<double> temperaturas;
    vector<char> caracteres;
    vector<int> anios;
    vector<double> velocidades;
    vector<double> distancias;

    voltajes = generar_voltajes();
    temperaturas = generar_temperaturas();    
    caracteres = generar_caracteres();
    anios = generar_anios();
    velocidades = generar_velocidades();
    distancias = generar_distancias();

    mostrar_voltajes(voltajes);
    mostrar_temperaturas(temperaturas);
    mostrar_caracteres(caracteres);
    mostrar_anios(anios);
    mostrar_velocidades(velocidades);
    mostrar_distancias(distancias);
    // Debido a la longitud de las listas, sólo se mostrarán los primeros 10 número/caracteres generados.

    return 0;
}

vector<double> generar_voltajes()
{
    vector<double> voltajes;
    int voltaje_entero;
    double voltaje;
    for (int i = 0; i < 100; i++)
    {
        voltaje_entero = (rand() % (22000 - 2000 + 1)) + 2000;
        voltaje = voltaje_entero / 100.00;
        voltajes.push_back(voltaje);
    }
    return voltajes;
}

vector<double> generar_temperaturas()
{
    vector<double> temperaturas;
    int temperatura_entera;
    double temperatura;
    for (int i = 0; i < 50; i++)
    {
        temperatura_entera = rand() % 10001;
        temperatura = temperatura_entera / 100.00;
        temperaturas.push_back(temperatura);
    }
    return temperaturas;
}

vector<char> generar_caracteres()
{
    vector<char> caracteres;
    string alfanumericos = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 30; i++)
    {
        int indice = rand() % alfanumericos.size();
        caracteres.push_back(alfanumericos[indice]);
    }

    return caracteres;
}

vector<int> generar_anios()
{
    vector<int> anios;
    int anio;
    for (int i = 0; i < 100; i++)
    {
        anio = (rand() % (2025 - 1990 + 1)) + 1990;
        anios.push_back(anio);
    }
    return anios;
}

vector<double> generar_velocidades()
{
    vector<double> velocidades;
    int velocidad_entera;
    double velocidad;
    for (int i = 0; i < 32; i++)
    {
        velocidad_entera = (rand() % (30000 - 1000 + 1)) + 1000;
        velocidad = velocidad_entera / 100.00;
        velocidades.push_back(velocidad);
    }
    return velocidades;
}

vector<double> generar_distancias()
{
    vector<double> distancias;
    int distancia_entera;
    double distancia;
    for (int i = 0; i < 1000; i++)
    {
        distancia_entera = (rand() % 100000) + 1;
        distancia = distancia_entera / 100.00;
        distancias.push_back(distancia);
    }
    return distancias;
}

void mostrar_voltajes(vector<double> voltajes)
{
    cout << "Primeros 10 voltajes:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << voltajes[i] << endl;
    }
    cout << "\n";
}

void mostrar_temperaturas(vector<double> temperaturas)
{
    cout << "Primeras 10 temperaturas:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << temperaturas[i] << endl;
    }
    cout << "\n";
}

void mostrar_caracteres (vector<char> caracteres)
{
    cout << "Primeros 10 caracteres:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << caracteres[i] << endl;
    }
    cout << "\n";
}

void mostrar_anios(vector<int> anios)
{
    cout << "Primeros 10 anios:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << anios[i] << endl;
    }
    cout << "\n";
}

void mostrar_velocidades(vector<double> velocidades)
{
    cout << "Primeras 10 velocidades:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << velocidades[i] << endl;
    }
    cout << "\n";
}

void mostrar_distancias(vector<double> distancias)
{
    cout << "Primeras 10 distancias:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << distancias[i] << endl;
    }
    cout << "\n";
}