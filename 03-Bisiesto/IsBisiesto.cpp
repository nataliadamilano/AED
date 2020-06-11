#include <cassert>

bool IsBisiesto(unsigned);

int main()
{
	assert(not IsBisiesto(1582));
	assert(IsBisiesto(1600));
	assert(not IsBisiesto(1800));
	assert(not IsBisiesto(1998));
	assert(IsBisiesto(2000));
	assert(IsBisiesto(2020));
}

bool IsBisiesto(unsigned anio)
{
	//return ((anio > 1582) and (anio%4 == 0) and (not (anio%100 == 0)) or (anio%400 == 0);
	return (anio > 1582) and (anio % 400 == 0) or (anio % 4 == 0) and not(anio % 100 == 0);
}
