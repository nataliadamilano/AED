/* 04-Cond
* Se desarrolla la función F3, la cual es una función por partes. Se procede a realizar pruebas con assert para verificar 
    el correcto desarrollo de la función.
* Natalia Belén Damilano
 * 31/5/2020
 */

#include <iostream>
#include <cassert>     

double F3(double);

int main()
{
    
    assert(-4 == F3(-4));
    assert(-3 == F3(3));
    assert(4 == F3(4));

}

double F3(double x)
{
    return
        x >= -3 and x <= 3 ? -x : x;
}
