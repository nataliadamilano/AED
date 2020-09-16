/* 04-Color
 * Se pide realizar un tipo de dato Color a partir del modelo RGB, estableciendo un rango entre [0,255] para cada intensidad de los canales y se pide principalmente el
 * desarrollar una función que permita mezclar dos colores en partes iguales.
 * Natalia Belén Damilano
 * 10/09/2020
 */

#include <cmath>
#include <cstdint>
#include "Color.h"
#include <array>

using namespace std;


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

string GetHtmlRgb(Color color)
{
  
   string colorRed = ((char)color.red);
   string colorGreen = ((char)color.green);
   string colorBlue = ((char)color.blue);


    return "rgb(" + colorRed + "," + colorGreen + "," + colorBlue + ")";
}

bool IsIgual(Color color1, Color color2)
{
    return color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue;
}
