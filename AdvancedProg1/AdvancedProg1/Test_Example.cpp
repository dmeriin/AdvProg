#include <iostream>
#include "PersonArray_t.h"

using namespace std;

//====================================================

static int getValue() {
    int i;
    cout << "\nEnter integer value :";
    cin >> i;
    return i;
}

//====================================================

static Person_t* getPtr() {
	std::string strName;
	int age;
	Person_t* person;
    cout << "\nEnter Name:";
	cin >> strName;
	cout << "\nEnter Age:";
	cin >> age;

	person = new Person_t(age, strName);
	return person;
}

//====================================================

int main() {
    PersonArray_t arr(16);
    int  value = 0;
    Person_t* pPerson    = 0;
	bool cont = true;

    while(cont) {
    cout << 
     "\n| n | fst | lst | empty | ins | rmv | RmvAll |apd|prp| < | : ";

        char c;
        cin >> c;

        switch (c) {
            case 'n' :  cout << arr.getNumOfElements() << endl;
                        break;
            case 'f' :  cout << *arr.getFirst() << endl;
                        break;
            case 'l' :  cout << *arr.getLast() << endl;
                        break;
			case 'i':  pPerson = getPtr();
						arr.Insert(pPerson);
                        break;
			case 'r':   pPerson = getPtr();
						arr.Remove(*pPerson);
                        break;
            case 'R' :  arr.RemoveAll();
                        break;
			case 'a':	value = getValue();
						pPerson = getPtr();
						arr.Append(value, pPerson);
                        break;
			case 'p':	value = getValue();
						pPerson = getPtr();
						arr.Prepend(value, pPerson);
                        break;
			default:	cont = false; break;
	
		}
    }

    return 0;
}
