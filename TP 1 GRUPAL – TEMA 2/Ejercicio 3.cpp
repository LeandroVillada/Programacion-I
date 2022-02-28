// 3) Se dispone de una lista de 10 grupos de números y cada uno de los grupos estará compuesto por 5 números. Se pide determinar e informar:
// a) La cantidad de grupos en los que se detecten un total de 2 o más números primos consecutivos. Se informa 1 resultado al final de todo.
// b) Para cada uno de los grupos en los que se haya detectado números negativos, el mayor y el segundo mayor de los mismos. En los grupos sin negativos, informar “Grupo sin negativos”. Se informan 2 resultados por cada grupo. 
// c) El mayor número primo de todos los grupos, informando además en que grupo y en qué posición del mismo fue detectado. Se informan 3 resultados al final

#include <iostream>
using namespace std;

int main()
{
	system("color 6");
	// Variables
	int i, p, g, n;
	// Punto A
	int contadorDivisores;
	int contadorDeNumerosPrimosConsecutivos, gruposConPrimosConsecutivos = 0;
	bool primosConsecutivos;
	// Punto B
	int primerMaximoNegativo, segundoMaximoNegativo, temp;
	// Punto C
	int maximoPrimo = 0, posPrimo, pos_gp_Primo;
	// Desarrollo del Programa
	for (g = 1; g <= 1; g++)
	{
		// Punto A
		primosConsecutivos = false;
		contadorDeNumerosPrimosConsecutivos = 0;

		// Punto B
		primerMaximoNegativo = 0;
		segundoMaximoNegativo = 0;

		for (i = 1; i <= 5; i++)
		{
			contadorDivisores = 0;
			cout << "INGRESAR UN NUMERO: ";
			cin >> n;
			for (p = 1; p <= n; p++)
			{
				if ((n % p) == 0)
				{
					contadorDivisores++;
				}
			}
			if ((primosConsecutivos) && (contadorDivisores == 2))
			{
				contadorDeNumerosPrimosConsecutivos++;
			}
			if (contadorDivisores == 2)
			{
				// BuscarMaximoPrimo
				if (maximoPrimo == 0)
				{
					pos_gp_Primo = g;
					maximoPrimo = n;
					posPrimo = i;
				}
				else
				{
					if (n >= maximoPrimo)
					{
						pos_gp_Primo = g;
						maximoPrimo = n;
						posPrimo = i;
					}
				}

				// Punto A
				if (!primosConsecutivos)
				{
					primosConsecutivos = true;
				}
			}
			else
			{
				primosConsecutivos = false;
			}
			// Punto B
			if (n < 0)
			{
				if (primerMaximoNegativo == 0)
				{
					primerMaximoNegativo = n;
				}
				else
				{
					temp = primerMaximoNegativo;
					if (n > primerMaximoNegativo)
					{
						primerMaximoNegativo = n;
					}
					else if (n < primerMaximoNegativo)
					{
						segundoMaximoNegativo = n;
					}
					if (temp < primerMaximoNegativo)
					{
						segundoMaximoNegativo = temp;
					}
				}
			}
		}
		if (contadorDeNumerosPrimosConsecutivos >= 2)
		{
			gruposConPrimosConsecutivos++;
		}

		// Punto B
		if (primerMaximoNegativo < 0)
		{
			cout << "\nEL PRIMER MAXIMO ES: " << primerMaximoNegativo << endl << endl;
			if (segundoMaximoNegativo < 0)
			{
				cout << "EL SEGUNDO MAXIMO NEGATIVO ES: " << segundoMaximoNegativo << endl << endl;
			}
		}
		else
		{
			cout << "\nESTE GRUPO NO CONTIENE NEGATIVOS" << endl << endl;
		}
	}
	// Punto A
	cout << "LA CANTIDAD DE GRUPOS CON MAS DE 2 PRIMOS CONSECUTIVOS ES DE: " << gruposConPrimosConsecutivos << endl
		 << endl;

	// Punto C
	if (maximoPrimo != 0)
		cout << "MAXIMO PRIMO INGRESADO: " << maximoPrimo << " UBICACION: " << posPrimo << " GRUPO: " << pos_gp_Primo << endl;

	// Fin del Programa
	system("pause>nul");
	return 0;
}