#include "Meeting_t.h"

template <class T>
Meeting_t<T>::Meeting_t(T startTime, T endTime, string strSubject)
{
	m_startTime = startTime;
	m_endTime = endTime;
	m_strSubject = strSubject;
}

template <class T>
Meeting_t<T>::Meeting_t(const Meeting_t<T>& meeting)
{
	if (!(T is int || T is float))
	{
		thrown new exception;
	}

	m_startTime = meeting.startTime;
	m_endTime = meeting.endTime;
	m_strSubject = meeting.strSubject;
}

template <class T>
virtual Meeting_t<T>::~Meeting_t()
{
	
}

template <class T>
virtual void Meeting_t<T>::print(void)
{
	cout << *this << endl;
}

//operator==. Check only if meeting times intersect.
template <class T>
const virtual bool Meeting_t<T>::operator==(const Meeting_t<T>& otherMeeting)
{
	return ((m_startTime < otherMeeting.m_endTime && m_endTime > otherMeeting.m_startTime));
}

// write into output stream
template <class T>
virtual std::ostream& Meeting_t<T>::operator<< (std::ostream& os)
{
	os << "\Start time:   " << m_startTime
		<< "\nEnd time:    " << m_endTime
		<< "\nSubject:    " << m_strSubject;
	return os;
}
