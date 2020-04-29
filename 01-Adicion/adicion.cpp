#include <iostream>
using namespace std;

int main()
{
	int num1, num2, continuar;

	continuar = 0;

	while (continuar != 1)
	{
		cout << "Ingrese dos numeros enteros por pantalla, por favor. \n" << "Primer numero: ";
		cin >> num1;

		cout << "Segundo numero: ";
		cin >> num2;

		cout << "El resultado de la suma es: " << num1 + num2;

		cout << "\n";

		cout << "Desea continuar generando adiciones? Ingrese 0 si la respuesta es SI, de lo contrario ingrese un 1. \n";
		cin >> continuar;
		while (continuar < 0 || continuar > 1)
		{
			cout << "ERROR. Debe de ingresar una de las opciones sugeridas anteriormente para continuar.\n";
			cin >> continuar;
		}
	}
}