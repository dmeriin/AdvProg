#include "DayCalendar_t.h"
/*
template <class T>
DayCalendar_t<T>::DayCalendar_t()
{

}*/

template <class T>
DayCalendar_t<T>::~DayCalendar_t()
{
}

template <class T>
void DayCalendar_t<T>::addMeeting(Meeting_t<T>* meeting)
{

}

template <class T>
bool DayCalendar_t<T>::deleteMeeting(T startTime)
{
	return false;
}

template <class T>
Meeting_t<T>* DayCalendar_t<T>::findMeeting(T startTime)
{
	return 0;
}

template <class T>
void DayCalendar_t<T>::print(void)
{
	
}


// write into output stream
template <class T>
virtual std::ostream& Meeting_t<T>::operator<< (std::ostream& os)
{
	return os;
}