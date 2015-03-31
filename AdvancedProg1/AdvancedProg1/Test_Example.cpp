#include <iostream>
#include "PersonArray_t.h"

using namespace std;

//====================================================

static int getValue() {
    int i = 0;
	while (!(cin >> i) || (i < 0) )
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Incorrect choice !\nplease enter your a positive numberic value" << endl;
	}
    return i;
}

//====================================================

static Person_t* getPtr() {
	std::string strName;
	unsigned int age;
	Person_t* person;
    cout << "\nEnter Name:";
	cin >> strName;
	cout << "\nEnter Age:";
	age = getValue();

	person = new Person_t(age, strName);
	return person;
}

//====================================================

int main() {
    PersonArray_t arr(16);
    int  value = 0;
    Person_t* pPerson = 0;
	Person_t * foundPerson = 0;
	Person_t * removedPerson = 0;
	bool cont = true;

	while (cont) {

		cout << "enter your choice number" << endl
			<< "1  - Get capacity of the array." << endl
			<< "2  - Get number of elements in the array." << endl
			<< "3  - Get the first Element in the array." << endl
			<< "4  - Get the last element in the array." << endl
			<< "5  - Find element in the array." << endl
			<< "6  - Insert new element to the array." << endl
			<< "7  - Append a new element after specific index in the array." << endl
			<< "8  - Prepand a element before specific place in the array " << endl
			<< "9  - Remove element from the array." << endl
			<< "10 - Remove all elements from the array." << endl
			<< "11 - Remove and Delete elements with specific value from the array." << endl
			<< "12 - Remove and delete all elements from the array." << endl
			<< "Any other number - quit" << endl;

		unsigned int c;
	
		// if numeric value
		if (cin >> c)
		{

			switch (c) {
            
				case 1	:  cout << arr.getCapacity() << endl;
							break;
				case 2	:  cout << arr.getNumOfElements() << endl;
							break;
				case 3	:  if (arr.getFirst()==NULL)
							{
								cout << "The array is empty." << endl;
							}
						   else
							{
							   cout << *arr.getFirst() << endl;
							 }
							break;
				case 4	:  
							if (arr.getLast() == NULL)
							{
								cout << "The array is empty." << endl;
							}
							else
							{
								cout << *arr.getLast() << endl;
							}
							break;
				case 5	:	pPerson = getPtr();
							foundPerson = arr.Find(*pPerson);
							if (foundPerson == 0)
							{
								cout << "The person is not in the array" << endl;
							}
							else{
								cout << "The following person has been found: " << endl;
								cout << *foundPerson << endl;
							}
							break;
				case 6	:	pPerson = getPtr();
							arr.Insert(pPerson);
							cout <<"The new person has been inserted to the array"<< endl;
							break;
				case 7	:	cout << "Enter index for appending the person: ";
							value = getValue();
							pPerson = getPtr();
							if (arr.Append(value, pPerson)){
								cout << "The new person successfully appended" << endl;
							}
							else{
								cout << "Failed to append the new person !" << endl;
							}
							break;
				case 8	:	cout << "Enter index for Prepending the person: ";
							value = getValue();
							pPerson = getPtr();
							if (arr.Prepend(value, pPerson)){
								cout << "The new person successfully appended" << endl;
							}
							else{
								cout << "Failed to prepend the new person !" << endl;
							}
							break;
				case 9	:	pPerson = getPtr();
							removedPerson = arr.Remove(*pPerson);
							if (removedPerson == 0)
							{
								cout << "The person is not in the array" << endl;
							}
							else{
								cout << "The following person has been removed: " << endl;
								cout << *removedPerson << endl;
							}
							break;
				case 10	:	arr.RemoveAll();
							cout << "All the elements from the array has been removed."<<endl;
							break;
				case 11	:	pPerson = getPtr();
							arr.RemoveAndDelete(*pPerson);
							cout << "All the matching elements from the array has been removed and deleted." << endl;
							break;
				case 12	:	arr.RemoveAndDeleteAll();
							cout << "All the elements from the array has been removed and deleted." << endl;
							break;
				default:	cont = false; break;
	
			}
		}
		else
		{
			// Non numeric value, quit.
			break;
		}
    }

    return 0;
}
