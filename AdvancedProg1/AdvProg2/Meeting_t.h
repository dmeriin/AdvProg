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
	
	inline Meeting_t(const Meeting_t<T>&)
	{
		if (!(T is int || T is float))
		{
			thrown new exception;
		}

		m_startTime = meeting.startTime;
		m_endTime = meeting.endTime;
		m_strSubject = meeting.strSubject;
	}

	virtual inline ~Meeting_t()
	{

	}

	virtual inline T getStartTime(void)
	{
		return m_startTime;
	}

	// write into output stream
	template <class J>
	friend std::ostream& operator<< (std::ostream& os, const Meeting_t<J>& meeting);

	virtual inline void print(void)
	{
		cout << *this << endl;
	}

	//operator==. Check only if meeting times intersect.
	const virtual inline bool operator==(const Meeting_t<T>& otherMeeting)
	{
		return ((m_startTime < otherMeeting.m_endTime && m_endTime > otherMeeting.m_startTime));
	}




protected:
	T m_startTime;
	T m_endTime;
	string m_strSubject;

};

template <class J>
std::ostream& operator<< (std::ostream& os, const Meeting_t<J>& meeting)
{
	os << "\nStart time:   " << meeting.m_startTime
		<< "\nEnd time:    " << meeting.m_endTime
		<< "\nSubject:    " << meeting.m_strSubject;
	return os;
}

#endif