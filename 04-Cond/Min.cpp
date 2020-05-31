/* 04-Cond
* Se desarrolla la función valor absoluto pidiéndole por teclado al usuario un entero para poder
efectuar la ejecución de la función y así obtener su resultado.
* Natalia Belén Damilano
 * 31/5/2020
 */

#include <iostream>
#include <assert.h>     

double Min(double, double);

int main()
{
    double a, b;

    std::cout << "Este es un prototipo para determinar el valor minimo entre dos valores dados, deberá de ingresar dos numeros cualquiera. \n";

    std::cout << "\nPrimer num: ";
    std::cin >> a;

    std::cout << "\nSegundo num: ";
    std::cin >> b;

    assert(-3 == Min(-3, 5.7));
    assert(0 == Min(0, 1));
    assert(10.233 == Min(10.3, 10.233));

    a < b ? assert(a == Min(a,b)) : assert(b == Min(a,b));
    
    std::cout << "El minimo es: " + std::to_string(Min(a, b));
    std::cout << " \n";

    system("pause");
}

double Min(double a, double b)
{
    return (a < b) ? a : b;
}
