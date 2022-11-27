#ifndef _deck_h_
#define _deck_h_

#include "Picture.h"

struct PictureNode
{
	Picture* data;
	PictureNode* next;
};

class Deck
{
public:
	Deck() = default;
	~Deck();

	Deck(const Deck&) = delete;
	Deck(Deck&&) noexcept;
	Deck& operator=(Deck&&) noexcept;

	void ResetCursor();
	void AdvanceCursor();
	bool IsCursorAtEnd() const;
	Picture* GetCursorValue() const;
	Picture* TakePicture(int number);

	Deck& operator+=(Picture* value);
	bool operator%(int number) const;

	friend std::ostream& operator<<(std::ostream& ostream, const Deck& rhs);

private:
	void FreePictureList();

	PictureNode* m_PictureList = nullptr;
	PictureNode* m_Cursor = nullptr;
};

#endif // _deck_h_