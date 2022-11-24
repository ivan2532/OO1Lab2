#include "Buket.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void TestFunction()
{
	Cvet a("Maslacak", 10, 15);
	Cvet b("Tulipan", 50, 70);
	Cvet c("Maslacak", 20, 30);
	Cvet d("CvetD", 22, 33);

	std::cout << a << " " << b << " " << c << std::endl;
	std::cout << (a == b) << " " << (b == c) << " " << (a == c) << std::endl;

	Buket buket1;
	buket1.AddFlower(a);
	buket1.AddFlower(b);
	buket1.AddFlower(c);
	buket1.AddFlower(d);
	buket1.AddFlower(d);
	buket1.AddFlower(d);

	Buket buket2;
	buket2.AddFlower(a);
	buket2.AddFlower(b);
	buket2.AddFlower(c);
	buket2.AddFlower(d);

	std::cout
		<< buket1
		<< " | BP:" << buket1.GetBuyPrice()
		<< " | SP:" << buket1.GetSellPrice()
		<< " | P:" << buket1.GetProfit()
		<< std::endl;

	std::cout << (buket1 > buket2);
}

int main()
{
	TestFunction();

	_CrtDumpMemoryLeaks();
	return 0;
}