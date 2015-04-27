#ifndef __MEETING_T_H__
#define __MEETING_T_H__

#include <string>
#include <iostream>

using namespace std;

template <class T>
class Meeting_t{
public:
	inline Meeting_t(T startTime, T endTime, string strSubject)
	{
		if (endTime > startTime)
		{
			m_startTime = startTime;
			m_endTime = endTime;
			m_strSubject = strSubject;
		}
		else
		{
			throw exception("End time must be later than start time.");
		}
	}
	
	inline Meeting_t(const Meeting_t<T>&meeting)
	{
		m_startTime = meeting.m_startTime;
		m_endTime = meeting.m_endTime;
		m_strSubject = meeting.m_strSubject;
	}

	virtual inline ~Meeting_t()
	{

	}

	virtual inline T getStartTime(void) const
	{
		return m_startTime;
	}

	virtual inline T getEndTime(void) const
	{
		return m_endTime;
	}

	virtual inline string getSubject(void) const
	{
		return m_strSubject;
	}

	virtual inline void print(void)
	{
		cout << *this << endl;
	}

	//operator==. Check only if meeting times intersect.
	const virtual inline bool operator==(const Meeting_t<T>& otherMeeting)
	{
		return (m_startTime < otherMeeting.m_endTime && m_endTime > otherMeeting.m_startTime);
	}




protected:
	T m_startTime;
	T m_endTime;
	string m_strSubject;

};

template <class J>
std::ostream& operator<< (std::ostream& os, const Meeting_t<J>& meeting)
{
	os << "\nStart time:   " << meeting.getStartTime()
		<< "\nEnd time:    " << meeting.getEndTime()
		<< "\nSubject:    " << meeting.getSubject();
	return os;
}

#endif