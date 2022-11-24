#include "Buket.h"

Buket::Buket(const Buket& value)
{
	auto it = value.flowerList;
	while (it != nullptr)
	{
		AddFlower(it->data);
	}
}

Buket::Buket(Buket&& value) noexcept
{
	flowerList = value.flowerList;
	value.flowerList = nullptr;
}

Buket::~Buket()
{
	auto it = flowerList;
	auto next = it;

	while (it != nullptr)
	{
		next = it->next;
		delete it;
		it = next;
	}
}

void Buket::AddFlower(const Cvet& value)
{
	auto newFlower = new CvetNode{ value, nullptr };
	
	if (flowerList == nullptr)
	{
		flowerList = newFlower;
		return;
	}

	auto lastFlower = flowerList;
	while (lastFlower->next != nullptr)
		lastFlower = lastFlower->next;

	lastFlower->next = newFlower;
}

int Buket::GetBuyPrice() const
{
	int sum = 0;

	auto it = flowerList;
	for (; it != nullptr; it = it->next)
		sum += it->data.GetBuyPrice();

	return sum;
}

int Buket::GetSellPrice() const
{
	int sum = 0;

	auto it = flowerList;
	for (; it != nullptr; it = it->next)
		sum += it->data.GetSellPrice();

	return sum;
}

int Buket::GetProfit() const
{
	int sum = 0;

	auto it = flowerList;
	for (; it != nullptr; it = it->next)
		sum += it->data.GetProfit();

	return sum;
}

bool Buket::operator>(const Buket& rhs) const
{
	return GetSellPrice() > rhs.GetSellPrice();
}

std::ostream& operator<<(std::ostream& ostream, const Buket& value)
{
	auto it = value.flowerList;
	bool firstFlower = true;

	for (; it != nullptr; it = it->next)
	{
		auto curCvet = it->data;
		auto distinctionIt = value.flowerList;
		bool isUnique = true;

		// Check if we already printed this flower O(n^2)
		for (; distinctionIt != it; distinctionIt = distinctionIt->next)
		{
			if (distinctionIt->data == curCvet)
			{
				isUnique = false;
				break;
			}
		}

		if (isUnique)
		{
			if (!firstFlower)
				ostream << ",";

			firstFlower = false;
			ostream << it->data << it->data.GetSellPrice() << "RSD";
		}
	}

	return ostream;
}
