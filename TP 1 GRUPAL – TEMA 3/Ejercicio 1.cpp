// 1) Hacer un programa para ingresar 5 números, luego informar los 2 mayores valores ingresados, aclarando cual es el máximo y cual el que le sigue.
// Ejemplo: 10, 8, 12, 14, 3 el resultado será 14 y 12.
// Ejemplo: 14, 8, 12, 14 ,3 el resultado será 14 y 14.
// Ejemplo: -4, -8, -12, -20, -2 el resultado será -2 y -4.
// Ejemplo: 14, 8, 12, 7 ,3 el resultado será 14 y 12.

#include <iostream>
using namespace std;

int main()
{
    // system("color 6");
    // Variables
    int n;
    int primerMaximo, segundoMaximo, temp;
    int contador = 0;

    // Desarrollo del Programa
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        if (contador == 0)
        {
            primerMaximo = n;
            contador++;
        }
        else if (contador == 1)
        {
            contador++;
            if (n > primerMaximo)
            {
                segundoMaximo = primerMaximo;
                primerMaximo = n;
            }
            else
            {
                segundoMaximo = n;
            }
        }
        else
        {
            temp = primerMaximo;
            if (n > primerMaximo)
            {
                primerMaximo = n;
            }
            if (temp < primerMaximo)
            {
                segundoMaximo = temp;
            }
            else if(n>segundoMaximo){
                segundoMaximo=n;
            }
        }
    }
    cout << "EL PRIMER MAXIMO ES: " << primerMaximo << endl;
    cout << "EL SEGUNDO MAXIMO ES: " << segundoMaximo << endl;

    // Fin del Programa
    system("pause>nul");
    return 0;
}