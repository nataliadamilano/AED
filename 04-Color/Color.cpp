/* 04-Color
 * Se pide realizar un tipo de dato Color a partir del modelo RGB, estableciendo un rango entre [0,255] para cada intensidad de los canales y se pide principalmente el
 * desarrollar una función que permita mezclar dos colores en partes iguales.
 * Natalia Belén Damilano
 * 10/09/2020
 */

#include <cassert>
#include <cmath>
#include <cstdint>
#include "Color.h"

using namespace std;


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

Color Mezclar(Color color1, Color color2)
{
    uint8_t avgRed = (color1.red + color2.red) / 2;

    uint8_t avgGreen = (color1.green + color2.green) / 2;

    uint8_t avgBlue = (color1.blue + color2.blue) / 2;

    return { avgRed, avgGreen, avgBlue };
}

Color MezclarProporciones(Color color1, unsigned partesColor1, Color color2, unsigned partesColor2)
{
    uint8_t avgRed = (color1.red + color2.red) / (partesColor1 + partesColor2);

    uint8_t avgGreen = (color1.green + color2.green) / (partesColor1 + partesColor2);

    uint8_t avgBlue = (color1.blue + color2.blue) / (partesColor1 + partesColor2);

    return { avgRed, avgGreen, avgBlue };
}


Color Sumar(Color color1, Color color2)
{
    uint8_t sumRed = color1.red + color2.red > MAX ? MAX : color1.red + color2.red;

    uint8_t sumGreen = color1.green + color2.green > MAX ? MAX : color1.green + color2.green;

    uint8_t sumBlue = color1.blue + color2.blue > MAX ? MAX : color1.blue + color2.blue;

    return { sumRed, sumGreen, sumBlue };
}

Color Restar(Color color1, Color color2)
{
    uint8_t sumRed = color1.red - color2.red < MIN ? MIN : color1.red - color2.red;

    uint8_t sumGreen = color1.green - color2.green < MIN ? MIN : color1.green - color2.green;

    uint8_t sumBlue = color1.blue - color2.blue < MIN ? MIN : color1.blue - color2.blue;

    return { sumRed, sumGreen, sumBlue };
}

Color GetComplementario(Color color)
{
    return color.red == rojo.red && color.green == rojo.green && color.blue == rojo.blue ? cian :
        color.red == verde.red && color.green == verde.green && color.blue == verde.blue ? magenta :
        amarillo;
}

string GetHtmlHex(Color color)
{
    char hexaColor[7];
    sprintf(hexaColor, "#%02x%02x%02x", color.red, color.green, color.blue);

    return hexaColor;
}

bool IsIgual(Color color1, Color color2)
{
    return color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue;
}
