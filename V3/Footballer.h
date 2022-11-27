#ifndef _footballer_h_
#define _footballer_h_

#include <string>
#include <ostream>

enum Position
{
	GK,
	DEF,
	MID,
	FWD
};

class Footballer
{
public:
	Footballer(const std::string& name, const std::string& team, Position position);
	Footballer(const Footballer&) = delete;

	std::string GetName() const { return m_Name; }
	std::string GetTeam() const { return m_Team; }

	Position GetPosition() const { return m_Position; }
	void SetPosition(Position value) { m_Position = value; }

	friend std::ostream& operator<<(std::ostream& ostream, const Footballer& rhs);

private:
	static std::string GetPositionText(Position value);

	std::string m_Name;
	std::string m_Team;
	Position m_Position;
};

#endif // _footballer_h_