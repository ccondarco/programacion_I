// Materia: Programación I, Paralelo 4
// Autor: Ana Cecilia Condarco Troncoso
// Carnet: 6142435 LP
// Carrera del estudiante: Diseño Digital
// Fecha creación: 09/10/2025
// Número de ejercicio: 7

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> generar_pixeles_aleatorios(int cantidad_pixeles);
void imprimir_pixeles(vector<int> pixeles_generados);
void generar_limites_de_rangos(vector<int>& limites_inferiores, vector<int>& limites_superiores);
vector<int> contar_pixeles_por_rango(vector<int> pixeles, vector<int> limites_inferiores, vector<int> limites_superiores);
void mostrar_resultado(vector<int> contador_pixeles, vector<int> limites_inferiores, vector<int> limites_superiores);

int main()
{
    system("chcp 65001");
    system("cls");

    int cantidad_pixeles;
    vector<int> pixeles_generados;
    vector<int> limites_inferiores;
    vector<int> limites_superiores;
    vector<int> pixeles_por_rango;

    cout << "Ingresar la cantidad de pixeles a generar: ";
    cin >> cantidad_pixeles;

    srand(time(0));

    pixeles_generados = generar_pixeles_aleatorios(cantidad_pixeles);
    imprimir_pixeles(pixeles_generados);

    generar_limites_de_rangos(limites_inferiores, limites_superiores);
    pixeles_por_rango = contar_pixeles_por_rango(pixeles_generados, limites_inferiores, limites_superiores);

    mostrar_resultado(pixeles_por_rango, limites_inferiores, limites_superiores);

    return 0;
}

vector<int> generar_pixeles_aleatorios(int cantidad_pixeles)
{
    int pixel_generado;
    vector<int> pixeles_generados;

    for (int i = 0; i < cantidad_pixeles; i++)
    {
        pixel_generado = rand() % 256;
        pixeles_generados.push_back(pixel_generado);
    }
    return pixeles_generados;
}

void imprimir_pixeles(vector<int> pixeles_generados)
{
    cout << "Pixeles generados:" << endl;

    for (int i = 0; i < pixeles_generados.size(); i++)
    {
        cout << pixeles_generados[i] << " ";
    }
    cout << endl;
}

void generar_limites_de_rangos(vector<int>& limites_inferiores, vector<int>& limites_superiores)
{
    for (int i = 0; i < 250; i+=10)
    {
        limites_inferiores.push_back(i);
    }
    for (int i = 9; i < 255; i+=10)
    {
        limites_superiores.push_back(i);
    }
    limites_superiores.push_back(255);
}

vector<int> contar_pixeles_por_rango(vector<int> pixeles, vector<int> limites_inferiores, vector<int> limites_superiores)
{
    int cantidad_rangos = limites_inferiores.size();
    vector<int> contador_pixeles(cantidad_rangos, 0);
    // Un elemento por cada rango que hay.
    int valor_actual;

    for (int i = 0; i < pixeles.size(); i++)
    {
        valor_actual = pixeles[i];
        for (int j = 0; j < cantidad_rangos; j++)
        {
            if (valor_actual >= limites_inferiores[j] && valor_actual <= limites_superiores[j])
            {
                contador_pixeles[j] = contador_pixeles[j] + 1;
                // Se suma 1 al rango correspondiente.
            }   
        }
    }
    return contador_pixeles;
}

void mostrar_resultado(vector<int> contador_pixeles, vector<int> limites_inferiores, vector<int> limites_superiores)
{
    int cantidad_rangos;

    cantidad_rangos = limites_inferiores.size();

    for (int i = 0; i < cantidad_rangos; i++)
    {
        cout << limites_inferiores[i] << " - " << limites_superiores[i] << ": " << contador_pixeles[i];

        if (contador_pixeles[i] == 1)
        {
            cout << " píxel" << endl;
        }
        else
        {
            cout << " píxeles" << endl;
        }   
    }
}