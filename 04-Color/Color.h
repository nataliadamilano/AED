#include <string>
#include <cstdint>

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
string GetHtmlRgb(Color color);
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
