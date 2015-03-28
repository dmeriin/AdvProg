#ifndef __ARRAY_T_H__
#define __ARRAY_T_H__
//----------------------------------------------------------------------------

#include <string>
#include <new> //for new exception(bad_alloc)
using namespace std;

#include "TException_t.h"
#include "Container_t.h"

//----------------------------------------------------------------------------

template <class T> class Array_t: public Container_t <T>
{
	public:
		
		#define DFLT_ARR_INIT_SIZE		2
		
		//DFLT CTOR
		Array_t(int _initSize = DFLT_ARR_INIT_SIZE);						
		
		//copy CTOR
		Array_t(const Array_t&);		
		
		//DTOR
		virtual ~Array_t(){delete [] m_arr;}						
		
		//operator=
		const Array_t& operator=(const Array_t&);	
		
		//Insert T element at end of a container
	 	virtual void Insert(const T&);			
		
		//Remove T element at specific index
		virtual  T Remove(int); 	
		
		//RemoveAll – empty container
		virtual void RemoveAll();		
		
		//Find – find element in container (by index)
		virtual const T& Find(int) const;		 
				
		//Print - 	print container
		virtual void Print() const;  						
	
	
	private:
		T *m_arr;
		int m_capacity;  				
		
		
		//------------help funcs------------

		void MyRealloc();	
		//shift left (1 index) int is the index to shift left from	
		const Array_t& operator<<(int); 	
		
};


//----------------------------------------------------------------------------
//																			  
//							   CLASS IMPLEMENTATION							  
//----------------------------------------------------------------------------


//DFLT CTOR
template <class T>
Array_t<T>::Array_t(int _initSize)
{
	try
	{
		m_arr = new T[_initSize];
		m_capacity = _initSize;
	}
	catch (bad_alloc&)
	{
		int err = BAD_ALLOC;
		throw TException_t<int>(err, __FILE__, __LINE__, "bad alloc");
	}	
}


//----------------------------------------------------------------------------

// copy CTOR
template <class T>
Array_t<T>::Array_t(const Array_t& _obj)
{
	try
	{
		m_arr = new T[_obj.m_capacity];
		
		//done just if allocation succedded
		Container_t<T>::m_numOfElements = _obj.m_numOfElements;
		m_capacity = _obj.m_capacity;
		
		for(int i=0; i<_obj.m_numOfElements; i++)
		{
			m_arr[i] = _obj.m_arr;
		}
	}
	catch (bad_alloc& ba)
	{
		int err = BAD_ALLOC;
		throw TException_t<int>(err, __FILE__, __LINE__, "bad alloc");
	}	
}		


//----------------------------------------------------------------------------

// operator=
template <class T>
const Array_t<T>& Array_t<T>:: operator=(const Array_t& _obj)
{
	if(this != &_obj)
	{	
		try
		{
			T *temp = new T[_obj.m_capacity];
		
			//done just if allocation succedded
			delete [] m_arr;
			m_arr = temp; 
			Container_t<T>::m_numOfElements = _obj.m_numOfElements;
			m_capacity = _obj.m_capacity;
			
			for(int i=0; i<_obj.m_numOfElements; i++)
			{
				m_arr[i] = _obj.m_arr;
			}
		}
		catch (bad_alloc& ba)
		{
			int err = BAD_ALLOC;
			throw TException_t<int>(err, __FILE__, __LINE__, "bad alloc");
		}	
		
	}
} 

//----------------------------------------------------------------------------

// Insert T element at end of a container
template <class T>
void Array_t<T>:: Insert(const T& _item)
{
	if(Container_t<T>::m_numOfElements >= m_capacity)
	{
		try
		{
			MyRealloc(); 
		}
		catch(int)
		{
			throw;	
		}
	}
	m_arr[Container_t<T>::m_numOfElements] = _item;
	++Container_t<T>::m_numOfElements;			
}			

//----------------------------------------------------------------------------

// Remove T element at specific index
template <class T>
T Array_t<T>::Remove(int _index)
{
	T temp;
	temp = m_arr[_index];
	try
	{
		*this<<_index; //shift left
	}
	catch(int)
	{
		throw;
	}
	return temp;
} 	

//----------------------------------------------------------------------------

// RemoveAll – empty container
template <class T>
void Array_t<T>::RemoveAll()
{
	Container_t<T>::m_numOfElements = 0;
}		

//----------------------------------------------------------------------------

// Find – find element in container (by index)
template <class T>
const T& Array_t<T>::Find(int _index) const
{
	if(_index > Container_t<T>::m_numOfElements)
	{
			int err = INDEX_OUT_OF_BOUNDES;
			throw TException_t<int>(err, __FILE__, __LINE__, "index out of boundes");
	}
	return m_arr[_index];
}		 

//----------------------------------------------------------------------------
		
// Print - 	print container
template <class T>
void Array_t<T>::Print() const
{
	if(Container_t<T>::m_numOfElements == 0)
	{
		cout<<"no items"<<endl;
		return;
	}
	cout<< "The array is: ";
	for(int i=0; i< Container_t<T>::m_numOfElements; i++)
	{
		cout<<m_arr[i]<<" "; 
	}
	cout<<endl;
} 						


//----------------------------------------------------------------------------

template <class T>
void Array_t<T>::MyRealloc()
{
	try
	{
		T *temp = new T[m_capacity*2];
	
		//done just if allocation succedded
		for(int i=0; i< Container_t<T>::m_numOfElements; i++)
		{
			temp[i] = m_arr[i];
		}
		m_arr = temp;
		m_capacity *= 2;
	}
	catch (bad_alloc&)
	{
		int err = BAD_ALLOC;
		throw TException_t<int>(err, __FILE__, __LINE__, "bad alloc");
	}		
}

//----------------------------------------------------------------------------

// shift left (1 index) int is the index to shift left from	
template <class T>

const Array_t<T>& Array_t<T>::operator<<(int _index)
{
	if(_index > Container_t<T>::m_numOfElements)
	{
		int err = INDEX_OUT_OF_BOUNDES;
		throw TException_t<int>(err, __FILE__, __LINE__, "index out of boundes");
	}
	else if(_index < Container_t<T>::m_numOfElements)
	{
		for(int i=_index; i<(Container_t<T>::m_numOfElements - 1); i++)
		{
			m_arr[i] = m_arr[i+1];
		}		 
	}
	
	// if the index to run over is the last item of the array (index == numOfElements)
	--Container_t<T>::m_numOfElements;
	return *this;
} 	

#endif // __ARRAY_T_H__
















