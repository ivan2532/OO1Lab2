#ifndef _picture_h_
#define _picture_h_

#include <string>
#include <ostream>

class Picture
{
	friend class PrintingOffice;

private:
	Picture(int number, const std::string& name)
		:
		m_Number(number),
		m_Name(name),
		m_ID(s_IDCounter++)
	{
	}

	Picture(const Picture&) = delete;

public:
	int GetNumber() const { return m_Number; }
	std::string GetName() const { return m_Name; }
	int GetID() const { return m_ID; }

	friend std::ostream& operator<<(std::ostream& ostream, const Picture& rhs)
	{
		ostream << "Slicica " << rhs.m_Number << " - " << rhs.m_Name << " (" << rhs.m_ID << ")";
		return ostream;
	}

private:
	int m_Number;
	std::string m_Name;
	int m_ID;

	static int s_IDCounter;
};

#endif // _picture_h_