/* 04-Cond
* Se desarrolla la función de valor mínimo entre dos valores dados. Para verificar que el desarrollo está
    bien hecho, se procede a realizar pruebas con assert.
* Natalia Belén Damilano
 * 31/5/2020
 */

#include <iostream>
#include <cassert>     

double Min(double, double);

int main()
{

    assert(-3 == Min(-3, 5.7));
    assert(0 == Min(0, 1));
    assert(10.233 == Min(10.3, 10.233));

}

double Min(double a, double b)
{
    return (a < b) ? a : b;
}
