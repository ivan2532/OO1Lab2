#include "FlowerShop.h"

FlowerShop::FlowerShop(const FlowerShop& value)
{
	*this = value;
}

FlowerShop& FlowerShop::operator=(const FlowerShop& rhs)
{
	if (this != &rhs)
	{
		FreeBouquetList();

		auto it = rhs.m_BouquetList;
		for (; it != nullptr; it = it->next)
			AddBouquet(it->data);

		// Very important to copy earnings after adding the bouquets because AddBouquet changes earnings!
		m_Earnings = rhs.m_Earnings;
	}

	return *this;
}

FlowerShop::FlowerShop(FlowerShop&& value) noexcept
{
	*this = value;
}

FlowerShop& FlowerShop::operator=(FlowerShop&& rhs) noexcept
{
	FreeBouquetList();
	m_Earnings = rhs.m_Earnings;
	m_BouquetList = rhs.m_BouquetList;
	rhs.m_BouquetList = nullptr;

	return *this;
}

FlowerShop::~FlowerShop()
{
	FreeBouquetList();
}

void FlowerShop::AddBouquet(const Bouquet& value)
{
	if (value.GetProfit() < value.GetBuyPrice() * 0.2)
		return;

	auto newNode = new BouquetNode{ value, nullptr };

	BouquetNode* insertPoint = nullptr; // New node will be right after insertPoint
	BouquetNode* it = m_BouquetList;

	for (; it != nullptr; it = it->next)
	{
		if (it->data > value)
			break;
		else
			insertPoint = it;
	}

	if (insertPoint == nullptr)
	{
		newNode->next = m_BouquetList;
		m_BouquetList = newNode;
	}
	else
	{
		newNode->next = insertPoint->next;
		insertPoint->next = newNode;
	}

	m_Earnings -= value.GetBuyPrice();
}

int FlowerShop::SellBouquet(unsigned pos)
{
	if (m_BouquetList == nullptr)
		return -1;

	BouquetNode* prev = nullptr;
	BouquetNode* it = m_BouquetList;

	for(; pos > 0; pos--)
	{
		if (it == nullptr)
			return -1;

		prev = it;
		it = it->next;
	}

	if (prev == nullptr)
		m_BouquetList = it->next;
	else
		prev->next = it->next;

	delete it;
	return 0;
}

void FlowerShop::FreeBouquetList()
{
	auto it = m_BouquetList;
	auto next = it;

	while (it != nullptr)
	{
		next = it->next;
		delete it;
		it = next;
	}

	m_BouquetList = nullptr;
}

std::ostream& operator<<(std::ostream& ostream, const FlowerShop& rhs)
{
	ostream << "zarada=" << rhs.m_Earnings << "RSD" << std::endl;

	for (auto it = rhs.m_BouquetList; it != nullptr; it = it->next)
	{
		ostream << it->data;
		if (it->next != nullptr)
			ostream << std::endl;
	}
	return ostream;
}
