#ifndef _cvecara_h_
#define _cvecara_h_

#include "Bouquet.h"

struct BouquetNode
{
	Bouquet data;
	BouquetNode* next;
};

class FlowerShop
{
public:
	FlowerShop() = default;
	~FlowerShop();

	FlowerShop(const FlowerShop&);
	FlowerShop& operator=(const FlowerShop&);

	FlowerShop(FlowerShop&&) noexcept;
	FlowerShop& operator=(FlowerShop&&) noexcept;

	void AddBouquet(const Bouquet& value);
	int SellBouquet(unsigned pos); // Returns 0 when successful, -1 when pos is out of bounds

	friend std::ostream& operator<<(std::ostream& ostream, const FlowerShop& rhs);
private:
	void FreeBouquetList();

	BouquetNode* m_BouquetList = nullptr;
	int m_Earnings = 1000;
};

#endif _cvecara_h_