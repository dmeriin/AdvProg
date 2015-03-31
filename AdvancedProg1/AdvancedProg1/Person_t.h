#ifndef __PERSON_T_H__
#define __PERSON_T_H__

#include <string>
#include <iostream>

#pragma once
class Person_t
{
public:
	//Ctor
	Person_t();

	Person_t(int age, std::string name);

	Person_t::Person_t(const Person_t& p);


	inline size_t getId() const{
		return m_id;
	}

	inline int getAge() const{
		return m_age;
	}

	const std::string& getName() const;

	//operator=
	const Person_t& operator=(const Person_t&) ;

	//operator==
	const bool operator==(const Person_t&) const;


	//Dtor
	~Person_t();

private:
	const size_t 		m_id;		// Unique for each Person_t object
	std::string				m_name;
	int					m_age;
	static size_t		m_globID ;	// used to calculate m_id 

};


// write into output stream
std::ostream& operator<< (std::ostream& os, const Person_t& p);

#endif // __PERSON_T_H__