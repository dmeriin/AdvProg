#ifndef __DAY_CALENDAR_T_H__
#define __DAY_CALENDAR_H__

#include <string>
#include <iostream>
#include "Meeting_t.h"

using namespace std;

template <class T>
class DayCalendar_t
{
public:
	inline DayCalendar_t() {};
	inline virtual ~DayCalendar_t() {};
	
	inline virtual void addMeeting(Meeting_t<T>* meeting) {}

	inline virtual bool deleteMeeting(T startTime) { return false; }

	inline virtual Meeting_t<T>* findMeeting(T startTime) { return new Meeting_t<T>(3,9,"D"); }

	inline virtual void print(void) { cout << this << endl; }

	// write into output stream
	template <class J>
	friend std::ostream& operator<< (std::ostream& os, const DayCalendar_t<J>& calendar);

};

template <class J>
std::ostream& operator<< (std::ostream& os, const DayCalendar_t<J>& calendar)
{

}

#endif