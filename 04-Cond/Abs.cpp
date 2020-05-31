/* 04-Cond
* Se desarrolla la función valor absoluto pidiéndole por teclado al usuario un entero para poder
efectuar la ejecución de la función y así obtener su resultado.
* Natalia Belén Damilano
 * 31/5/2020
 */

#include <iostream>
#include <assert.h>     

int Abs(int);

int main()
{
    int num;

    std::cout << "Este es un prototipo para determinar el resultado de una función valor absoluto |x|. \n"
        "Ingrese un valor entero (Z) cualquiera para obtener el resultado final: ";

    std::cin >> num;

    assert(3 == Abs(-3));
    assert(0 == Abs(0));
    assert(3 == Abs(3));

    num < 0 ? assert(-num == Abs(num)) : assert(num == Abs(num));

    std::cout << "Resultado: |" + std::to_string(num) + "|=" + std::to_string(Abs(num));
    std::cout << " \n";

    system("pause");
}

int Abs(int x)
{
    return x<0 ? -x : x;
}
