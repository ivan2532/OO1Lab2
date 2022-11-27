#include "FlowerShop.h"

int main()
{
	Flower a_Original("Maslacak", 10, 15);
	Flower b_Old("Tulipan", 50, 70);
	Flower c("Maslacak", 20, 30);
	Flower d("CvetD", 22, 33);

	Flower a(a_Original);
	Flower b = std::move(b_Old);

	std::cout << a << " " << b << " " << c << std::endl;
	std::cout << (a == b) << " " << (b == c) << " " << (a == c) << std::endl;

	std::cout << std::endl;

	Bouquet bouquet1;
	bouquet1.AddFlower(a);
	bouquet1.AddFlower(b);
	bouquet1.AddFlower(c);
	bouquet1.AddFlower(d);
	bouquet1.AddFlower(d);
	bouquet1.AddFlower(d);

	Bouquet bouquet2;
	bouquet2.AddFlower(a);
	bouquet2.AddFlower(b);
	bouquet2.AddFlower(c);
	bouquet2.AddFlower(d);

	std::cout
		<< bouquet1
		<< " | BP:" << bouquet1.GetBuyPrice()
		<< " | SP:" << bouquet1.GetSellPrice()
		<< " | P:" << bouquet1.GetProfit()
		<< std::endl;

	bouquet1 = std::move(bouquet2);
	Bouquet bouquet3(bouquet1);

	std::cout
		<< bouquet1
		<< " | BP:" << bouquet1.GetBuyPrice()
		<< " | SP:" << bouquet1.GetSellPrice()
		<< " | P:" << bouquet1.GetProfit()
		<< std::endl;
	std::cout
		<< bouquet2
		<< " | BP:" << bouquet2.GetBuyPrice()
		<< " | SP:" << bouquet2.GetSellPrice()
		<< " | P:" << bouquet2.GetProfit()
		<< std::endl;
	std::cout
		<< bouquet3
		<< " | BP:" << bouquet3.GetBuyPrice()
		<< " | SP:" << bouquet3.GetSellPrice()
		<< " | P:" << bouquet3.GetProfit()
		<< std::endl;

	std::cout << (bouquet1 > bouquet2) << std::endl;

	std::cout << std::endl;

	bouquet3 = Bouquet();
	bouquet3.AddFlower(b);
	FlowerShop shop1, shop2;
	shop1.AddBouquet(bouquet1);
	shop1.AddBouquet(bouquet3);
	shop1.AddBouquet(bouquet1);
	shop1.AddBouquet(bouquet3);
	shop2 = shop1;

	Flower cheap("Cheap", 10, 10);
	Bouquet bouquet4;
	bouquet4.AddFlower(cheap);
	FlowerShop shop3;
	shop3.AddBouquet(bouquet4);
	shop3.AddBouquet(bouquet1);

	std::cout << shop1 << std::endl << std::endl << shop2 << std::endl << std::endl << shop3;

	std::cout << std::endl;
	std::cout << std::endl;

	shop1 = std::move(shop3);
	shop2 = shop1;

	std::cout << shop1 << std::endl << std::endl << shop2 << std::endl << std::endl << shop3;

	shop1.SellBouquet(0);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << shop1 << std::endl << std::endl << shop2 << std::endl << std::endl << shop3;

	shop1.AddBouquet(bouquet1);
	shop1.AddBouquet(bouquet3);
	shop1.AddBouquet(bouquet1);
	shop1.AddBouquet(bouquet3);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << shop1;

	std::cout << std::endl;
	std::cout << "SELL1: " << shop1.SellBouquet(2);
	//std::cout << std::endl;
	//std::cout << "SELL2: " << shop1.SellBouquet(2);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << shop1;

	return 0;
}