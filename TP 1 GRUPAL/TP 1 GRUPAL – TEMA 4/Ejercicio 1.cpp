// 1) Hacer un programa para ingresar una lista de 10 números, luego informar el máximo y la posición del máximo en la lista. En caso de “empates” considerar la primera aparición.
// Ejemplo: 5, -10, 20, 8, 25, 13, 35, -8, -5, 20. Se listará Máximo 35 Posición 7.
// Ejemplo: 5, -10, 20, 8, 25, 13, 55, -8, 55, 20. Se listará Máximo 55 Posición 7.
#include <iostream>
using namespace std;

int main()
{
    system("color 6");
    // Variables
    int n, maximo = -9999999, posicion;

    // Desarrollo del Programa
    for (int i = 0; i < 10; i++)
    {
        cin >> n;
        if (n > maximo)
        {
            maximo = n;
            posicion = i + 1;
        }
    }
    cout << "\nMAXIMO: " << maximo << " POSICION: " << posicion << endl;

    // Fin del Programa
    system("pause>nul");
    return 0;
}