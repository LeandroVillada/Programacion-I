// 2) Se define como divisores propios de un número a aquellos que son sus divisores excluyendo al número en sí mismo.
// Ejemplo. Los divisores propios del 4 son: 1 y 2.
// Ejemplo. Los divisores propios del 12 son: 1, 2, 3, 4 y 6
// Se define a un número como perfecto cuando la suma de todos sus divisores propios coincide con el número en sí mismo.
// Ejemplo: 6 es número perfecto pues 1+2+3=6
// Ejemplo: 28 es número perfecto pues 1+2+4+7+14=28
// Ejemplo: 12 no es número perfecto pues 1+2+3+4+6=16
// Hacer un programa para ingresar un número y luego informar con un cartel aclaratorio si el mismo es un número perfecto o es número no perfecto.
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
        cin >> n;
        if (n == 0)
            break;
        divisores = 0;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
            {
                divisores += i;
            }
        }
        if (divisores == n)
            cout << "PERFECTO." << endl;
        else
            cout << "NO PERFECTO." << endl;
    }

    // Fin del Programa
    // system("pause>nul");
    return 0;
}