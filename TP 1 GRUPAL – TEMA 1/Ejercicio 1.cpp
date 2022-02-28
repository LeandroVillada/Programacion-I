// 1) Hacer un programa para ingresar una lista de 10 números, luego informar el máximo de los pares.
// Ejemplo: 2, 10, 20, 8, 25, 13, 36, -8, -5, 20. Se listará Máximo 36.
// Ejemplo: 5, -13, 23, 81, -55, -13, 55, 4, 15, -20. Se listará Máximo 4.
// Ejemplo: -5, -13, -20, -8, -55, -13, -55, -14, -15, -20. Se listará Máximo -8.
#include <iostream>
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int n, maximoPar = 0;

    // Desarrollo del Programa
    for (int i = 0; i < 10; i++)
    {
        cin >> n;
        if (n % 2 == 0)
        {
            if (maximoPar == 0)
                maximoPar = n;
            else if (n > maximoPar)
                maximoPar = n;
        }
    }
    cout << "\nMAXIMO PAR INGRESADO: " << maximoPar << endl;

    // Fin del Programa
    system("pause>nul");
    return 0;
}