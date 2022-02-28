// Dada una lista de 7 números informar cual es el anteúltimo y último número impar ingresado.
// Ejemplo 8, 4, -5, 6, 10, 5, 18 se informa -5 y 5.
// Ejemplo 5, 7, 8, 10, 22, 10, 6 se informa 5 y 7.
#include <iostream>
#include <cstdlib>
using namespace std;

// Prototipos de Funciones
void cargarVector(int *, int);
int buscarAnteultimo(int *, int);
int buscarUltimoImpar(int *, int);

int main()
{
    system("color 6");
    // Variables
    int num[7];

    // Desarrollo del Programa
    cargarVector(num, 7);
    cout << "\nANTEULTIMO NUMERO INGRESADO: " << buscarAnteultimo(num, 7) << endl;
    cout << "ULTIMO NUMERO IMPAR INGRESADO: " << buscarUltimoImpar(num, 7) << endl;

    // Fin del Programa
    system("pause>nul");
    return 0;
}

// Desarrollo de Funciones
void cargarVector(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << "INGRESAR UN NUMERO: ";
        cin >> v[i];
    }
}
int buscarAnteultimo(int *v, int tam)
{
    return v[tam - 2];
}
int buscarUltimoImpar(int *v, int tam)
{
    int impar;
    for (int i = 0; i < tam; i++)
    {
        if (v[i] % 2 != 0)
            impar = v[i];
    }
    return impar;
}