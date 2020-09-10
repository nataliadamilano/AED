#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

const uint8_t MAX = 255;
const uint8_t MIN = 0;


struct Color { uint8_t red, green, blue; };

Color Mezclar(Color color1, Color color2);
Color MezclarProporciones(Color color1, unsigned partesColor1, Color color2, unsigned partesColor2);
Color Sumar(Color color1, Color color2);
Color Restar(Color color1, Color color2);
Color GetComplementario(Color color);
string GetHtmlHex(Color color);
bool IsIgual(Color color1, Color color2);

/* COLORES PRIMARIOS */
const Color rojo{ 255,0,0 };
const Color amarillo{ 255,255,0 };
const Color azul{ 0,0,255 };

/* COLORES SECUNDARIOS */
const Color verde = Restar(amarillo, rojo);
const Color cian = Sumar(verde, azul);
const Color magenta = Sumar(rojo, azul);

const Color blanco = Sumar(verde, magenta);
const Color negro = Restar(blanco, blanco);



int main()
{
    cout << GetHtmlHex(rojo);
}

Color Mezclar(Color color1, Color color2)
{
    uint8_t avgRed = (color1.red + color2.red) / 2;
    cout << unsigned(avgRed) << endl;
    uint8_t avgGreen = (color1.green + color2.green) / 2;
    cout << unsigned(avgGreen) << endl;
    uint8_t avgBlue = (color1.blue + color2.blue) / 2;
    cout << unsigned(avgBlue);


    return { avgRed, avgGreen, avgBlue };
}

Color MezclarProporciones(Color color1, unsigned partesColor1, Color color2, unsigned partesColor2)
{
    uint8_t avgRed = (color1.red + color2.red) / (partesColor1 + partesColor2);
    cout << unsigned(avgRed) << endl;
    uint8_t avgGreen = (color1.green + color2.green) / (partesColor1 + partesColor2);
    cout << unsigned(avgGreen) << endl;
    uint8_t avgBlue = (color1.blue + color2.blue) / (partesColor1 + partesColor2);
    cout << unsigned(avgBlue);

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