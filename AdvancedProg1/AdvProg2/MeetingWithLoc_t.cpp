#include "MeetingWithLoc_t.h"

template <class T>
MeetingWithLoc_t<T>::MeetingWithLoc_t(T startTime, T endTime, string strSubject, string strLocation )
					: Meeting_t( startTime, endTime, strSubject )
{
	m_strLocation = strLocation;
}

template <class T>
MeetingWithLoc_t<T>::MeetingWithLoc_t(const MeetingWithLoc_t<T>& meeting)
					: Meeting_t(meeting)
{
	m_strLocation = meeting.m_strLocation;
}