#include <cassert>
#include "Color.h"

int main()
{
    // Pruebas

    assert(IsIgual({ 127,127,0 }, Mezclar(rojo, verde)));
    assert(IsIgual({ 0,127,127 }, Mezclar(azul, verde)));
    assert(IsIgual({ 127,0,127 }, Mezclar(azul, rojo)));
    assert(IsIgual(blanco, Mezclar(blanco, blanco)));

    assert(IsIgual({ 85,0,85 }, MezclarProporciones(azul, 2, rojo, 1)));
    assert(IsIgual({ 170,85,0 }, MezclarProporciones(amarillo, 2, rojo, 1)));
    assert(IsIgual({ 85,42,42 }, MezclarProporciones(blanco, 4, rojo, 2)));

    assert(IsIgual(cian, Sumar(verde, azul)));
    assert(IsIgual(magenta, Sumar(rojo, azul)));
    assert(IsIgual(blanco, Sumar(verde, magenta)));

    assert(IsIgual(negro, Restar(blanco, blanco)));
    assert(IsIgual(verde, Restar(amarillo, rojo)));

    assert(IsIgual(cian, GetComplementario(rojo)));
    assert(IsIgual(magenta, GetComplementario(verde)));
    assert(IsIgual(amarillo, GetComplementario(azul)));

    assert("#ff0000" == GetHtmlHex(rojo));
    assert("#ffff00" == GetHtmlHex(amarillo));
    assert("#0000ff" == GetHtmlHex(azul));
    assert("#00ff00" == GetHtmlHex(verde));
    assert("#00ffff" == GetHtmlHex(cian));
    assert("#ff00ff" == GetHtmlHex(magenta));
    assert("#000000" == GetHtmlHex(negro));
    assert("#ffffff" == GetHtmlHex(blanco));

    assert("rgb(255,255,255)" == GetHtmlRgb(blanco));
    assert("rgb(255,255,0)" == GetHtmlRgb(negro));

    assert(!IsIgual(amarillo, rojo));
    assert(IsIgual(verde, { 0,255,0 }));
    assert(!IsIgual(magenta, { 255,255,0 }));
    assert(IsIgual(magenta, { 255,0,255 }));
    assert(!IsIgual(rojo, azul));
    assert(IsIgual(cian, Sumar(verde, azul)));
    assert(!IsIgual(negro, { 0,1,0 }));
    assert(IsIgual(negro, { 0,0,0 }));
    assert(IsIgual(negro, Restar(blanco, blanco)));

}
