#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void imprimir(string nombre, string apellido, int edad);

int main()
{
	system("chcp 65001");
    system("cls");

    vector<string> nombres = {"Luciana", "Mario", "Diana", "Ernesto", "Majo", "Christian", "Gyllian", "Daniel", "Camila", "Luis"};
	vector<string> apellidos = {"Vega", "Callejas", "Perez", "Revollo", "Cordero", "Rinaldo", "Venegas", "Sanjines", "Aguilar", "Fernandez"};
	vector<int> edades = {18, 51, 73, 30, 27, 7, 13, 60, 45, 58};
	int cantidad_a_imprimir;
    int indice_nombre;
    int indice_apellido;
    int indice_edad;

	cout << "Ingresar cantidad de veces a seleccionar: ";
	cin >> cantidad_a_imprimir;
	
	srand(time(0));

    for (int i = 0; i < cantidad_a_imprimir; i++)
    {
        indice_nombre = rand() % nombres.size();
        indice_apellido = rand() % apellidos.size();
        indice_edad = rand() % edades.size();
        imprimir(nombres[indice_nombre], apellidos[indice_apellido], edades[indice_edad]);
        // Se genera e imprime combinaciones aleatorias, eligiendo un índice al azar para cada vector.
    }
	
    return 0;
}

void imprimir(string nombre, string apellido, int edad)
{
    cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "Edad: " << edad << endl;
    cout << endl;
}