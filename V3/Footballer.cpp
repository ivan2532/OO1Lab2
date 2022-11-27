#include "Footballer.h"

Footballer::Footballer(const std::string& name, const std::string& team, Position position)
	:
	m_Name(name),
	m_Team(team),
	m_Position(position)
{
}

std::string Footballer::GetPositionText(Position value)
{
	switch (value)
	{
		default:
		case GK:
			return "GK";
		case DEF:
			return "DEF";
		case MID:
			return "MID";
		case FWD:
			return "FWD";
	}
}

std::ostream& operator<<(std::ostream& ostream, const Footballer& rhs)
{
	ostream << rhs.m_Name << "(" << Footballer::GetPositionText(rhs.m_Position) << "):" << rhs.m_Team;
	return ostream;
}
