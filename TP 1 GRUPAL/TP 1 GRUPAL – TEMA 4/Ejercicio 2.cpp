// 2) Hacer un programa para ingresar un número y luego informar todos los divisores de ese número.
// Ejemplo 1. Si se ingresa 6 se listarán: 1, 2, 3 y 6
// Ejemplo 2. Si se ingresa 9 se listarán 1, 3 y 9.
// Ejemplo 3. Si se ingresa 11 se listarán 1 y 11
#include <iostream>
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int n;

    // Desarrollo del Programa
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << "\nDIVISORES DEL NUMERO INGRESADO: ";
        for (int i = n; i > 0; i--)
        {
            if (n % i == 0)
                cout << n/i << " ";
        }
    }

    // Fin del Programa
    system("pause>nul");
    return 0;
}