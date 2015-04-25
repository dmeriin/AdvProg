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

	virtual inline string getLocation( void )
	{
		return m_strLocation;
	}

	virtual inline void setLocation( string strLocation )
	{
		m_strLocation = strLocation;
	}

	virtual ~MeetingWithLoc_t() {};
	
protected:
	string m_strLocation;
};


#endif