// Llamaremos a un vector EMPATADOS TOTAL aquel vector que tiene repetido el mismo valor en todas sus posiciones pares y también el mismo valor en todas sus posiciones impares
// Por ejemplo:
// v:i{0, 4, 0, 4, 0, 4, 0, 4, 0, 4} es un vector de EMPATADOS
// v:i{0, 4, 0, 4, 0, 4, 0, 4, 0} también es un vector de EMPATADOS
// v:i{0, 4, 3, 4, 0, 4, 0, 4, 0, 4} NO es un vector de EMPATADOS
// Pero también podemos tener un vector EMPATADOS PARCIAL, que es similar al anterior pero solo en un tramo del mismo.
// v:i{0, 4, 0, 4, 8, 2, 8, 4, 0, 4} es un vector de EMPATADOS PARCIAL pues en el tramo que va de la posición 0 a la posición 3 cumple la regla.
// Hacer una función para que dado un vector de tamaño N se indique mediante un cartel si el vector es EMPATADOS TOTAL, EMPATADOS PARCIAL O SIN EMPATES
#include <iostream>
using namespace std;

// Prototipos de Funciones
void cargarVector(int v[], int tam);
void compararEmpatados(int v[], int tam);

int main()
{
    system("color 6");
    // Variables
    int *vector, tamanio;

    // Desarrollo del Programa
    cout << "INGRESAR EL TAMANIO DEL VECTOR: ";
    cin >> tamanio;
    vector = new int[tamanio];
    cargarVector(vector, tamanio);
    compararEmpatados(vector, tamanio);

    // Fin del Programa
    // system("pause>nul");
    return 0;
}

// Desarrollo de Funciones
void cargarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << "INGRESE NUMERO: ";
        cin >> v[i];
    }
}
void compararEmpatados(int v[], int tam)
{
    int tramos = (tam - (tam % 2)) / 2, contador = 1;
    for (int i = 3; i < tam; i += 2)
    {
        if ((v[i] == v[i - 2]) & (v[i - 1] == v[i - 3]))
            contador++;
    }
    if (contador == tramos)
        cout << "EMPATADOS TOTAL." << endl;
    else if (contador != 1)
        cout << "EMPATADOS PARCIAL." << endl;
    else
        cout << "SIN EMPATES." << endl;
}
