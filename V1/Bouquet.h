#ifndef _buket_h_
#define _buket_h_

#include "Flower.h"

struct FlowerNode
{
	Flower data;
	FlowerNode* next;
};

class Bouquet
{
public:
	Bouquet() = default;
	~Bouquet();

	Bouquet(const Bouquet&);
	Bouquet& operator=(const Bouquet&);

	Bouquet(Bouquet&&) noexcept;
	Bouquet& operator=(Bouquet&&) noexcept;

	void AddFlower(const Flower& value);
	int GetBuyPrice() const;
	int GetSellPrice() const;
	int GetProfit() const;
	
	bool operator>(const Bouquet& rhs) const;
	bool operator<(const Bouquet& rhs) const;
	bool operator>=(const Bouquet& rhs) const;
	bool operator<=(const Bouquet& rhs) const;
	friend std::ostream& operator<<(std::ostream& ostream, const Bouquet& rhs);
private:
	void FreeFlowerList();

	FlowerNode* m_FlowerList = nullptr;
};

#endif // _buket_h_