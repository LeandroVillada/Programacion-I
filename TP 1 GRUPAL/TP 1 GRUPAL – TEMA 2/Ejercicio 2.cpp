// Dada una lista de 7 números informar el primer número par ingresado y su ubicación en la lista y el último de los números primos y su ubicación en la lista.
// Ejemplo 7, 4, 5, 6, 9, 13, 10 se informa Primer número par: 4 ubicación 2. Ultimo primo: 13 ubicación 6.
// Ejemplo 9, 5, 21, 9, 13, 15, 6 se informa Primer número par: 6 ubicación 7. Ultimo primo: 13 ubicación 5
#include <iostream>
#include <cstdlib>
using namespace std;

// Prototipos de Funciones
void cargarVector(int v[], int tam);
void buscarNumeroPar(int v[], int tam);
void buscarNumeroPrimo(int v[], int tam);

int main()
{
    system("color 6");
    // Variables
    int num[7];

    // Desarrollo del Programa
    cargarVector(num, 7);
    buscarNumeroPar(num, 7);
    buscarNumeroPrimo(num, 7);

    // Fin del Programa
    system("pause>nul");
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
void buscarNumeroPar(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (v[i] % 2 == 0)
        {
            cout << "PRIMER NUMERO PAR INGRESADO: " << v[i] << " UBICACION: " << i + 1 << endl;
            break;
        }
    }
}
void buscarNumeroPrimo(int v[], int tam)
{
    int primo, pos = 0, contador, i, j;
    for (i = 0; i < tam; i++)
    {
        contador = 0;
        for (j = 1; j <= v[i]; j++)
        {
            if (v[i] % j == 0)
            {
                contador++;
            }
        }
        if (contador == 2)
        {
            primo = v[i];
            pos = i + 1;
        }
    }
    cout << "ULTIMO NUMERO PRIMO: " << primo << " UBICACION: " << pos << endl;
}