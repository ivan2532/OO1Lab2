#include "Deck.h"

Deck::~Deck()
{
	FreePictureList();
}

Deck::Deck(Deck&& value) noexcept
{
	*this = std::move(value);
}

Deck& Deck::operator=(Deck&& rhs) noexcept
{
	if (this != &rhs)
	{
		FreePictureList();
		m_Cursor = rhs.m_Cursor;
		m_PictureList = rhs.m_PictureList;
		rhs.m_PictureList = nullptr;
	}

	return *this;
}

Deck& Deck::operator+=(Picture* value)
{
	if (value != nullptr)
	{
		auto newNode = new PictureNode{ value, nullptr };
		m_Cursor = newNode;

		if (m_PictureList == nullptr)
		{
			m_PictureList = newNode;
			return *this;
		}

		auto lastNode = m_PictureList;
		while (lastNode->next != nullptr)
			lastNode = lastNode->next;

		lastNode->next = newNode;
	}

	return *this;
}

bool Deck::operator%(int number) const
{
	for (auto* it = m_PictureList; it != nullptr; it = it->next)
	{
		if (it->data->GetNumber() == number)
			return true;
	}

	return false;
}

void Deck::FreePictureList()
{
	auto it = m_PictureList;
	auto next = it;

	while (it != nullptr)
	{
		next = it->next;
		delete it;
		it = next;
	}

	m_PictureList = nullptr;
}

void Deck::ResetCursor()
{
	m_Cursor = m_PictureList;
}

void Deck::AdvanceCursor()
{
	if (!IsCursorAtEnd())
		m_Cursor = m_Cursor->next;
}

bool Deck::IsCursorAtEnd() const
{
	return m_Cursor == nullptr;
}

Picture* Deck::GetCursorValue() const
{
	if (IsCursorAtEnd())
		return nullptr;

	return m_Cursor->data;
}

Picture* Deck::TakePicture(int number)
{
	if (m_PictureList == nullptr)
		return nullptr;

	Picture* result = nullptr;

	PictureNode* prev = nullptr;
	PictureNode* it = m_PictureList;

	while(it != nullptr)
	{
		if (it->data->GetNumber() == number)
		{
			result = it->data;
			break;
		}

		prev = it;
		it = it->next;
	}

	if (prev == nullptr)
		m_PictureList = it->next;
	else
		prev->next = it->next;

	delete it;
	return result;
}

std::ostream& operator<<(std::ostream& ostream, const Deck& rhs)
{
	bool firstLine = true;
	for (auto it = rhs.m_PictureList; it != nullptr; it = it->next)
	{
		if (!firstLine)
			ostream << std::endl;

		firstLine = false;
		ostream << *(it->data);
	}

	return ostream;
}
