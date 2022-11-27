#include "Bouquet.h"

Bouquet::Bouquet(const Bouquet& value)
{
	*this = value;
}

Bouquet& Bouquet::operator=(const Bouquet& rhs)
{
	if (this != &rhs)
	{
		FreeFlowerList();

		auto it = rhs.m_FlowerList;
		for (; it != nullptr; it = it->next)
			AddFlower(it->data);
	}

	return *this;
}

Bouquet::Bouquet(Bouquet&& value) noexcept
{
	*this = std::move(value);
}

Bouquet& Bouquet::operator=(Bouquet&& rhs) noexcept
{
	if (this != &rhs)
	{
		FreeFlowerList();
		m_FlowerList = rhs.m_FlowerList;
		rhs.m_FlowerList = nullptr;
	}

	return *this;
}

Bouquet::~Bouquet()
{
	FreeFlowerList();
}

void Bouquet::AddFlower(const Flower& value)
{
	auto newNode = new FlowerNode{ value, nullptr };
	
	if (m_FlowerList == nullptr)
	{
		m_FlowerList = newNode;
		return;
	}

	auto lastNode = m_FlowerList;
	while (lastNode->next != nullptr)
		lastNode = lastNode->next;

	lastNode->next = newNode;
}

int Bouquet::GetBuyPrice() const
{
	int sum = 0;

	auto it = m_FlowerList;
	for (; it != nullptr; it = it->next)
		sum += it->data.GetBuyPrice();

	return sum;
}

int Bouquet::GetSellPrice() const
{
	int sum = 0;

	auto it = m_FlowerList;
	for (; it != nullptr; it = it->next)
		sum += it->data.GetSellPrice();

	return sum;
}

int Bouquet::GetProfit() const
{
	int sum = 0;

	auto it = m_FlowerList;
	for (; it != nullptr; it = it->next)
		sum += it->data.GetProfit();

	return sum;
}

bool Bouquet::operator>(const Bouquet& rhs) const
{
	return GetSellPrice() > rhs.GetSellPrice();
}

void Bouquet::FreeFlowerList()
{
	auto it = m_FlowerList;
	auto next = it;

	while (it != nullptr)
	{
		next = it->next;
		delete it;
		it = next;
	}
}

std::ostream& operator<<(std::ostream& ostream, const Bouquet& rhs)
{
	auto it = rhs.m_FlowerList;
	bool firstFlower = true;

	for (; it != nullptr; it = it->next)
	{
		auto curCvet = it->data;
		auto distinctionIt = rhs.m_FlowerList;
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
