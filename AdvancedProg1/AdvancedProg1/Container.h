#ifndef __CONTAINER_T_H__
#define __CONTAINER_T_H__

#include "TException_t.h"


typedef enum
{
	BAD_ALLOC,
	INDEX_OUT_OF_BOUNDES,
	NO_FUNCTION_IN_DERIVED_CLASS	
}Errors;


template <class T> class Container_t
{
	public:
		
		//DFLT CTOR
		Container_t() : m_numOfElements(0) {}						
		
		//copy CTOR
		Container_t(const Container_t& _obj):m_numOfElements(_obj.m_numOfElements){}		
		
		//DTOR
		virtual ~Container_t() {}						
		
		//operator=
		const Container_t& operator=(const Container_t&) {}	
		
		//Insert T element at end of a container
		virtual void Insert(const T&)	= 0;			
		
		//Remove T element at specific index
		virtual T Remove(int)			= 0; 	
		
		//RemoveAll – empty container
		virtual void RemoveAll()		= 0;		
		
		//Find – find element in container (by index)
		virtual const T& Find(int) const= 0;		 
		
		//number of elements in container
		int Count(void) const{return m_numOfElements;}
		
		//Print - 	print container
		virtual void Print() const		= 0;  						
	
	protected:
		int m_numOfElements;		
				
	private:
	
		
};


#endif //__CONTAINER_T_H__




