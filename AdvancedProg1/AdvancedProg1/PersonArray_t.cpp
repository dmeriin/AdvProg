#include "PersonArray_t.h"


PersonArray_t::~PersonArray_t()
{
	delete[] m_arr; 
}


//DFLT CTOR
PersonArray_t::PersonArray_t(int _initSize)
{
	try
	{
		m_arr = new Person_t*[_initSize];
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

PersonArray_t::PersonArray_t(const PersonArray_t& _obj)
{
	try
	{
		m_arr = new Person_t*[_obj.m_capacity];

		//done just if allocation succedded
		m_numOfElements = _obj.m_numOfElements;
		m_capacity = _obj.m_capacity;

		// copy each person object
		for (int i = 0; i<_obj.m_numOfElements; i++)
		{
			m_arr[i] = new Person_t(*_obj.m_arr[i]);
		}
	}
	catch (bad_alloc&)
	{
		int err = BAD_ALLOC;
		throw TException_t<int>(err, __FILE__, __LINE__, "bad alloc");
	}
}


//----------------------------------------------------------------------------

// operator=
const PersonArray_t& PersonArray_t:: operator=(const PersonArray_t& _obj)
{
	if (this != &_obj)
	{
		try
		{
			Person_t **temp = new Person_t*[_obj.m_capacity];

			//done just if allocation succedded
			delete[] m_arr;
			m_arr = temp;
			m_numOfElements = _obj.m_numOfElements;
			m_capacity = _obj.m_capacity;

			// copy pointer of each person
			for (int i = 0; i<_obj.m_numOfElements; i++)
			{
				m_arr[i] = _obj.m_arr[i];
			}

		}
		catch (bad_alloc&)
		{
			int err = BAD_ALLOC;
			throw TException_t<int>(err, __FILE__, __LINE__, "bad alloc");
		}

	}
	return *this;
}

//----------------------------------------------------------------------------

// Insert Person_t element at end of a container, returns index of new element.
int PersonArray_t::Insert( Person_t* _item)
{
	int pos;

	if ( m_numOfElements >= m_capacity )
	{
		try
		{
			MyRealloc();
		}
		catch (int)
		{
			throw;
		}
	}

	pos = m_numOfElements;
	m_arr[pos] = _item;

	++m_numOfElements;

	return pos;
}

//----------------------------------------------------------------------------

//Insert Person_t element after given index
bool PersonArray_t::Append(int index, Person_t* p)
{
	
	if (m_numOfElements >= m_capacity)
	{
		try
		{
			MyRealloc();
		}
		catch (int)
		{
			throw;
		}
	}

	*this >> ( index + 1 );

	m_arr[index + 1] = p;
	return true;
}

//----------------------------------------------------------------------------

//Insert Person_t element after given index
bool PersonArray_t::Prepend(int index, Person_t* p)
{

	if (m_numOfElements >= m_capacity)
	{
		try
		{
			MyRealloc();
		}
		catch (int)
		{
			throw;
		}
	}

	*this >> (index);

	m_arr[index] = p;
	return true;
}

//----------------------------------------------------------------------------

// Remove element with the same values as p
Person_t* PersonArray_t::Remove(const Person_t& p)
{
	Person_t* retPerson = 0;
	bool found = false;
	int index = 0;

	while ( !found && ( index < m_numOfElements ) )
	{
		if (*m_arr[index] == p)
		{
			retPerson = m_arr[index];
			*this << index;
			found = true;
		}
		index++;
	}

	return retPerson;
}

//----------------------------------------------------------------------------

// RemoveAll – empty container

void PersonArray_t::RemoveAll()
{
	int i;
	for (i = 0; i < m_numOfElements; i++)
	{
		m_arr[i] = NULL;
	}
	m_numOfElements = 0;
}

//----------------------------------------------------------------------------

// remove and deletes element with specific values
// if more than one element has the same value, then to remove all of them
void PersonArray_t::RemoveAndDelete(const Person_t& p)
{

	Person_t* retPerson = 0;
	bool found = false;
	int index = 0;

	// Remove all occurrences and then delete the refernce. 
	while (index < m_numOfElements)
	{
		if (*m_arr[index] == p)
		{
			retPerson = m_arr[index];
			*this << index;
			delete retPerson;
		}
	}
}

//----------------------------------------------------------------------------

// Remove and delete all elements

void PersonArray_t::RemoveAndDeleteAll()
{
	int i;
	for (i = 0; i < m_numOfElements; i++)
	{
		delete m_arr[i] ;
	}
	m_numOfElements = 0;
}

//----------------------------------------------------------------------------

// Find – find element in container with the same values as p
Person_t* PersonArray_t::Find(const Person_t& p) const
{
	Person_t* retPerson = 0;
	bool found = false;
	int index = 0;

	while (!found && (index < m_numOfElements))
	{
		if (*m_arr[index] == p)
		{
			retPerson = m_arr[index];
			found = true;
		}
		index++;
	}

	return retPerson;
}


//----------------------------------------------------------------------------

void PersonArray_t::MyRealloc()
{
	try
	{
		Person_t **temp = new Person_t*[m_capacity * 2];

		//done just if allocation succedded
		for (int i = 0; i< m_numOfElements; i++)
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


// get first element in array
Person_t* PersonArray_t::getFirst() const
{
	Person_t* retPerson = NULL;

	if (m_numOfElements > 0)
	{
		retPerson = m_arr[0];
	}

	return retPerson;
}

//----------------------------------------------------------------------------

// last element in array
Person_t* PersonArray_t::getLast() const
{
	Person_t* retPerson = NULL;

	if (m_numOfElements > 0)
	{
		retPerson = m_arr[m_numOfElements - 1];
	}

	return retPerson;
}

//----------------------------------------------------------------------------

// shift left (1 index) int is the index to shift left from	

const PersonArray_t& PersonArray_t::operator<<(int _index)
{
	if (_index > m_numOfElements)
	{
		int err = INDEX_OUT_OF_BOUNDES;
		throw TException_t<int>(err, __FILE__, __LINE__, "index out of boundes");
	}
	else if (_index < m_numOfElements)
	{
		for (int i = _index; i<( m_numOfElements-1); i++)
		{
			m_arr[i] = m_arr[i + 1];
		}
	}

	// if the index to run over is the last item of the array (index == numOfElements)
	--m_numOfElements;
	return *this;
}

//----------------------------------------------------------------------------

// shift right (1 index) int is the index to shift right from	

const PersonArray_t& PersonArray_t::operator>>(int _index)
{
	if (_index > m_numOfElements)
	{
		int err = INDEX_OUT_OF_BOUNDES;
		throw TException_t<int>(err, __FILE__, __LINE__, "index out of boundes");
	}
	else
	{
		for (int i = m_numOfElements; i>(_index); i--)
		{
			m_arr[i] = m_arr[i - 1];
		}
	}

	++m_numOfElements;
	return *this;
}