#ifndef __DAY_CALENDAR_T_H__
#define __DAY_CALENDAR_H__

#include <string>
#include <iostream>
#include "Meeting_t.h"
#include <vector>

using namespace std;

template <class T>
class DayCalendar_t
{
public:
	DayCalendar_t();
	DayCalendar_t(const DayCalendar_t<T>& calendar);
	virtual ~DayCalendar_t();
	
	virtual void addMeeting(Meeting_t<T>* meeting);

	virtual bool deleteMeeting(T startTime);

	virtual Meeting_t<T>* findMeeting(T startTime) const;
	
	Meeting_t<T>* getMeetingFromIndex(int index) const;

	inline virtual void print(void) const
	{

		for (int i = 0; i < getNumOfMeetings(); i++)
		{
			getMeetingFromIndex(i)->print() ;
		}
	}

	inline int getNumOfMeetings() const
	{
		return m_vec.size();
	}


protected:
	int findMeetingIndex(T startTime) const;
	vector<Meeting_t<T>*> m_vec;
};

//default CTOR
template <typename T>
DayCalendar_t<T>::DayCalendar_t()
{
	
}

//copy CTOR
template <typename T>
DayCalendar_t<T>::DayCalendar_t(const DayCalendar_t<T>& calendar)
{
	for (size_t i = 0; i < calendar.getNumOfMeetings(); i++)
	{
		Meeting_t<T> *meeting = new Meeting_t<T>(*calendar.getMeetingFromIndex(i));
		this->m_vec.push_back(meeting);
	}
}

//DTOR
template <typename T>
DayCalendar_t<T>::~DayCalendar_t()
{
	for (int i = 0; i < m_vec.size(); i++)
	{
		delete (m_vec.at(i));
	}
	m_vec.clear();
}

template <typename T>
Meeting_t<T>* DayCalendar_t<T>::getMeetingFromIndex(int index) const
{
	if (index >= 0 && index<m_vec.size())
		return m_vec.at(index);
	return NULL;
}

// write into output stream
template <typename T>
ostream& operator<< (ostream& os, const DayCalendar_t<T>& calendar)
{
	for (int i = 0; i < calendar.getNumOfMeetings(); i++)
	{
		os << *calendar.getMeetingFromIndex(i)->print()<<endl;
	}
	return os;
}
template <typename T>
void DayCalendar_t<T>::addMeeting(Meeting_t<T>* meeting)
{
	
	if (m_vec.size() == 0){
		m_vec.insert(m_vec.begin(),meeting);
		return;
	}
	int i;
	for (i=0; i < m_vec.size(); i++)
	{
		if ((m_vec.at(i))->getStartTime() > meeting->getStartTime()){
			break;
		}
	}
	if (i < m_vec.size()){
		if (*m_vec.at(i) == *meeting){
			throw exception("There is an overlap between the meetings");
		}
	}
	if (i > 0){
		if (*m_vec.at(i - 1) == *meeting){
			throw exception("There is an overlap between the meetings");
		}
	}
	m_vec.insert(m_vec.begin() + i,meeting);
	
}

template <typename T>
bool DayCalendar_t<T>::deleteMeeting(T startTime)
{
	int meetingIndex = findMeetingIndex(startTime);

	if (meetingIndex == -1)
		return false;

	Meeting_t<T> *meetingToDelete = m_vec.at(meetingIndex);

	m_vec.erase(m_vec.begin() + meetingIndex);
	delete meetingToDelete;

	return true;
}

template <typename T>
Meeting_t<T>* DayCalendar_t<T>::findMeeting(T startTime) const
{
	int meetingIndex = findMeetingIndex(startTime);
	if (meetingIndex == -1)
		return NULL;
	return m_vec[meetingIndex];
}

template <typename T>
int DayCalendar_t<T>::findMeetingIndex(T startTime) const
{
	int i;
	for (i = 0; i < m_vec.size(); i++)
	{
		if (startTime == m_vec[i]->getStartTime()){
			return i;
		}
		if (startTime < m_vec[i]->getStartTime())
		{
			break;
		}
	}
	return -1;
}

#endif