/* 04-Cond
* Se desarrolla la función valor absoluto, para corroborar que cumpla las propiedades de la misma, se procede a hacer
    pruebas con assert.
* Natalia Belén Damilano
 * 31/5/2020
 */

#include <iostream>
#include <cassert>     

int Abs(int);

int main()
{

    /* Este es un prototipo para determinar el resultado de una función valor absoluto |x|. */


    assert(3 == Abs(-3));
    assert(0 == Abs(0));
    assert(3 == Abs(3));

}

int Abs(int x)
{
    return x<0 ? -x : x;
}
