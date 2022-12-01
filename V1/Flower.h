#ifndef _cvet_h_
#define _cvet_h_

#include <iostream>
#include <string>

class Flower
{
public:
	Flower(const std::string& name, int buyPrice, int sellPrice)
		:
		m_Name(name),
		m_BuyPrice(buyPrice),
		m_SellPrice(sellPrice)
	{
	}

	const std::string& GetName() const { return m_Name; }
	int GetBuyPrice() const { return m_BuyPrice; }
	int GetSellPrice() const { return m_SellPrice; }
	int GetProfit() { return m_SellPrice - m_BuyPrice; }

	bool operator ==(const Flower& rhs) const
	{
		return m_Name == rhs.m_Name;
	}

	bool operator !=(const Flower& rhs) const
	{
		return !(*this == rhs);
	}

	friend std::ostream& operator<<(std::ostream& ostream, const Flower& rhs)
	{
		return ostream << rhs.m_Name;
	}

private:
	std::string m_Name;
	int m_BuyPrice;
	int m_SellPrice;
};

#endif // _cvet_h_