#ifndef __PERSON_ARRAY_T_H__
#define __PERSON_ARRAY_T_H__
//----------------------------------------------------------------------------

#include <string>
#include <new> //for new exception(bad_alloc)
using namespace std;

#include "TException_t.h"
#include "Person_t.h"

//----------------------------------------------------------------------------

class PersonArray_t
{
	public:
		
		#define DFLT_ARR_INIT_SIZE		16
		
		//DFLT CTOR
		PersonArray_t(int _initSize = DFLT_ARR_INIT_SIZE);
						
		//DTOR
		~PersonArray_t();

		
		//Insert Person_t element at end of a container
		int PersonArray_t::Insert(Person_t* _item);

		 //Insert Person_t element after given index
		 bool Append( int index, Person_t*);

		 //Insert Person_t element before given index
		 bool Prepend( int index ,Person_t* );

		 // get first element in array
		 Person_t* getFirst() const;

		 // last element in array
		 Person_t* getLast() const;

		//Remove Person_t element with specific values
		// if more than one element has the same value, then to remove only the first found
		// Returns pointer to the person object if removed, NULL otherwise.
		 Person_t* Remove(const Person_t&);
		
		//RemoveAll – empty container
		 void RemoveAll();		

		 // remove and deletes element with specific values
		 // if more than one element has the same value, then to remove all of them
		 void RemoveAndDelete(const Person_t&);

		 // Remove and delete all
		 void RemoveAndDeleteAll();
		
		//Find – find element in container with specific values
		 Person_t* Find(const Person_t&) const;
	
		// Get number of elements in array
		 inline int getNumOfElements() const{
			 return m_numOfElements;
		 }

		 // Get capcity of array.
		 inline int getCapacity() const{
			 return m_capacity;
		 }
	
	private:
		Person_t **m_arr;
		int m_numOfElements;
		int m_capacity;  				

		//copy CTOR
		PersonArray_t(const PersonArray_t&);


		//operator=
		const PersonArray_t& operator=(const PersonArray_t&);
		
		//------------help funcs------------

		void MyRealloc();	
		//shift left (1 index) int is the index to shift left from	
		const PersonArray_t& operator<<(int);

		//shift right (1 index) int is the index to shift right from	
		const PersonArray_t& operator>>(int);
		
};


#endif // __PERSON_ARRAY_T_H__
















