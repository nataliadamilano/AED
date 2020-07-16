/* -Celsius
* Dada una magnitud en Fahrenheit, se calculará su equivalente en grados Celsius.
* Natalia Belén Damilano
 * 31/5/2020
 */

#include <cassert>

double Celsius(double);

bool AreNear(double, double, double = 0.001);

int main()
{
	assert(AreNear(Celsius(32.000), 0, 0.001)); // 32° F = 0° C, 0 - 0 = 0 y esto es <= 0.001 (tolerancia).
	assert(AreNear(Celsius(50.000), 10, 0.001)); // 50° F = 10° C, 10 - 10 = 0 y esto es <= 0.001 (tolerancia).
	assert(AreNear(Celsius(-32.000), -35.55556, 0.001)); // -32° F = -35.55556° C, -35.55556 - (-35.55556) = 0 y esto es <= 0.001 (tolerancia).
	assert(AreNear(Celsius(-25.600), -32.000, 0.001)); // -25.6° F = -32° C, -32 - (-32) = 0 y esto es <= 0.001 (tolerancia).
	assert(not(AreNear(Celsius(-22.000), -30.001, 0.001))); // -22° F = -30° C, -30 - (-30.001) = 0.001 y esto es > 0.001 (tolerancia).
}

double Celsius(double f)
{
	return
		(5.000 / 9.000) * (f - 32);
}

bool AreNear(double a, double b, double tolerancia)
{
	return
		(a >= b) ? (a - b) <= tolerancia
		: (b - a) <= tolerancia;
}
