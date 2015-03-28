#include "Person_t.h"

size_t Person_t::m_globID = 0;

Person_t::Person_t() : m_id(m_globID++)
{
	m_age = -1;
}


Person_t::Person_t(int age, std::string name) : Person_t()
{
	m_age = age;
	m_name = name;
}

size_t Person_t::getId() const
{
	return m_id;
}

const std::string& Person_t::getName() const
{
	return m_name;
}

int Person_t::getAge() const
{
	return m_age;
}

//operator=
const Person_t& Person_t::operator=(const Person_t& p) 
{
	if (this != &p)
	{
		m_name = p.getName();
		m_age = p.getId();

	}
	return *this;
}

//operator==
const bool Person_t::operator==(const Person_t& p) const
{
	return (( m_name == p.getName()) && 
			( m_age == p.getAge()));
}

std::ostream& operator<< (std::ostream& os, const Person_t& p) {

	os << "\nName:   " << p.getName()
		<< "\nAge:   " << p.getAge()
		<< "\nId:    " << p.getId();
	return os;
}


// String's destructor is called automatiaclly.
Person_t::~Person_t()
{

}
