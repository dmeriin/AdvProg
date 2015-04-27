#ifndef __MEETING_T_WITHLOC_H__
#define __MEETING_T_WITHLOC_H__

#include "Meeting_t.h"
#include <string>
#include <iostream>

using namespace std;

template <class T>
class MeetingWithLoc_t : public Meeting_t<T>
{
public:
	inline MeetingWithLoc_t(T startTime, T endTime, string strSubject, string strLocation) : 
		Meeting_t( startTime, endTime, strSubject )
	{
		m_strLocation = strLocation;
	}
	inline MeetingWithLoc_t(const MeetingWithLoc_t<T>&) :
		Meeting_t(startTime, endTime, strSubject)
	{
		m_strLocation = strLocation;
	}

	virtual inline string getLocation( void ) const
	{
		return m_strLocation;
	}

	virtual inline void setLocation( string strLocation )
	{
		m_strLocation = strLocation;
	}

	virtual inline void print(void)
	{
		cout << *this << endl;
	}

	virtual ~MeetingWithLoc_t() {};
	
protected:
	string m_strLocation;
};

template <class J>
std::ostream& operator<< (std::ostream& os, const MeetingWithLoc_t<J>& meeting)
{
	os << "\nStart time:   " << meeting.getStartTime()
		<< "\nEnd time:    " << meeting.getEndTime()
		<< "\nSubject:    " << meeting.getSubject()
		<< "\nLocation:	  " << meeting.getLocation();
	return os;
}


#endif