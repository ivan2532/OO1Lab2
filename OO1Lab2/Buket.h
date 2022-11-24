#ifndef _buket_h_
#define _buket_h_

#include "Cvet.h"

struct CvetNode
{
	Cvet data;
	CvetNode* next;
};

class Buket
{
public:
	Buket() = default;
	Buket(const Buket&);
	Buket(Buket&&) noexcept;
	~Buket();

	void AddFlower(const Cvet& value);
	int GetBuyPrice() const;
	int GetSellPrice() const;
	int GetProfit() const;
	
	bool operator>(const Buket& rhs) const;
	friend std::ostream& operator<<(std::ostream& ostream, const Buket& value);
private:
	CvetNode* flowerList = nullptr;
};

#endif // _buket_h_