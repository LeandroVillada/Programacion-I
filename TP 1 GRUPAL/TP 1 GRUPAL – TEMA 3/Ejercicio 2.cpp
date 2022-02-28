// 2) Hacer un programa para ingresar un número y luego informar la cantidad de divisores de ese número.
// Ejemplo 1. Si se ingresa 6 se listarán: 4 divisores.
// Ejemplo 2. Si se ingresa 9 se listarán: 3 divisores.
// Ejemplo 3. Si se ingresa 11 se listará: 2 divisores.
#include <iostream>
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int n, divisores;

    // Desarrollo del Programa
    while (true)
    {
        divisores = 0;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
                divisores++;
        }
        cout << "\nCANTIDAD DE DIVISORES: " << divisores << endl
             << endl;
    }

    // Fin del Programa
    return 0;
}