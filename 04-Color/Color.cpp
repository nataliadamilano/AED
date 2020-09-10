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

    assert(127 == Mezclar(rojo, verde).red && 127 == Mezclar(rojo, verde).green && 0 == Mezclar(rojo, verde).blue);
    assert(0 == Mezclar(azul, verde).red && 127 == Mezclar(azul, verde).green && 127 == Mezclar(azul, verde).blue);
    assert(127 == Mezclar(azul, rojo).red && 0 == Mezclar(azul, rojo).green && 127 == Mezclar(azul, rojo).blue);
    assert(255 == Mezclar(blanco, blanco).red && 255 == Mezclar(blanco, blanco).green && 255 == Mezclar(blanco, blanco).blue);

    assert(85 == MezclarProporciones(azul, 2, rojo, 1).red && 0 == MezclarProporciones(azul, 2, rojo, 1).green && 85 == MezclarProporciones(azul, 2, rojo, 1).blue);
    assert(170 == MezclarProporciones(amarillo, 2, rojo, 1).red && 85 == MezclarProporciones(amarillo, 2, rojo, 1).green && 0 == MezclarProporciones(amarillo, 2, rojo, 1).blue);
    assert(85 == MezclarProporciones(blanco, 4, rojo, 2).red && 42 == MezclarProporciones(blanco, 4, rojo, 2).green && 42 == MezclarProporciones(blanco, 4, rojo, 2).blue);

    assert(0 == Sumar(verde, azul).red && 255 == Sumar(verde, azul).green && 255 == Sumar(verde, azul).blue);
    assert(255 == Sumar(rojo, azul).red && 0 == Sumar(rojo, azul).green && 255 == Sumar(rojo, azul).blue);
    assert(255 == Sumar(verde, magenta).red && 255 == Sumar(verde, magenta).green && 255 == Sumar(verde, magenta).blue);


    assert(0 == Restar(blanco, blanco).red && 0 == Restar(blanco, blanco).green && 0 == Restar(blanco, blanco).blue);
    assert(0 == Restar(amarillo, rojo).red && 255 == Restar(amarillo, rojo).green && 0 == Restar(amarillo, rojo).blue);

    assert(cian.red == GetComplementario(rojo).red && cian.green == GetComplementario(rojo).green && cian.blue == GetComplementario(rojo).blue);
    assert(magenta.red == GetComplementario(verde).red && magenta.green == GetComplementario(verde).green && magenta.blue == GetComplementario(verde).blue);
    assert(amarillo.red == GetComplementario(azul).red && amarillo.green == GetComplementario(azul).green && amarillo.blue == GetComplementario(azul).blue);

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
