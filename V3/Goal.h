#ifndef _goal_h_
#define _goal_h_

#include "Footballer.h"

class Goal
{
public:
	Goal(Footballer* scorer, int minute)
		:
		m_Scorer(scorer),
		m_Minute(minute)
	{
	}

	Footballer* GetScorer() const { return m_Scorer; }

	friend std::ostream& operator<<(std::ostream& ostream, const Goal& rhs)
	{
		ostream << "[" << rhs.m_Minute << "']-" << *(rhs.m_Scorer);
		return ostream;
	}

private:
	Footballer* m_Scorer;
	int m_Minute;
};

#endif // _goal_h_