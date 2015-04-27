#include <iostream>
#include "Meeting_t.h"
#include "MeetingWithLoc_t.h"
#include "DayCalendar_t.h"

using namespace std;

//====================================================
template<class T>
static T getTimeValue() 
{
	throw new exception("Type not supported");
}

template<>
static int getTimeValue<int>() {
    float i = 0;
	int retVal = 0;
	bool isLegal = false;

	while (!isLegal)
	{
		if ((cin >> i) && (i >= 0 && i < 24))
		{
			retVal = i; // implicit cast to int, make sure input is integer.
			if (retVal == i)
			{
				isLegal = true;
			}
		}

		if (!isLegal)
		{
			cout << "Incorrect choice !\nplease enter a valid time value" << endl;
			cout << "Hours are between 0 to 23. e.g. 16" << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

    return i;
}

//====================================================
template<>
static float getTimeValue<float>() {
	float i = 0, minutes;
	int intVal = 0;
	bool isLegal = false;

	while (!isLegal)
	{
		if ((cin >> i) && (i >= 0 && i < 24))
		{
			intVal = i; // implicit cast to int, make sure number of period is between 0 and 59
			minutes = i - intVal;
			if (minutes >= 0.0 && minutes < 0.60)
			{
				isLegal = true;
			}
		}

		if (!isLegal)
		{
			cout << "Incorrect choice !\nplease enter a valid time value." << endl;
			cout << "Hours are between 0 to 23, minutes are between 0 to 59. e.g. 16.48 " << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return i;
}

//==================================================== Int Meeting handlers 

// meeting argument is passed only to signal the compiler about the type of the template
template<class T>
static Meeting_t<T>* getMeeting() {
	T startTime, endTime;
	string strSubject;
	Meeting_t<T>* meeting;
	cout << "\nEnter Subj:";
	ws(cin);
	getline(cin, strSubject);
	cout << "\nEnter Start time:";
	startTime = getTimeValue<T>();
	cout << "\nEnter End time:";
	endTime = getTimeValue<T>();


	meeting = new Meeting_t<T>(startTime, endTime, strSubject);
	return meeting;
}

// meeting argument is passed only to signal the compiler about the type of the template
template<class T>
static MeetingWithLoc_t<T>* getMeetingWithLoc() {
	T startTime, endTime;
	string strSubject, strLocation;
	MeetingWithLoc_t<T>* meeting;

	cout << "\nEnter Subj:";
	ws(cin);
	getline(cin, strSubject);
	cout << "\nEnter Start time:";
	startTime = getTimeValue<T>();
	cout << "\nEnter End time:";
	endTime = getTimeValue<T>();
	cout << "\nEnter Location:";
	cin >> strLocation;



	meeting = new MeetingWithLoc_t<T>(startTime, endTime, strSubject, strLocation);
	return meeting;
}

template<typename T>
static void testMenu(DayCalendar_t<T>* calendar)
{
	bool cont = true , hasDeleted;

	Meeting_t<T>* regularMeeting;
	MeetingWithLoc_t <T>* locationMeeting;
	DayCalendar_t<T> *cal;
	T startTime;

	while (cont) {

		cout << "\nenter your choice number" << endl
			<< "1  - Add regular meeting." << endl
			<< "2  - Add meeting with location." << endl
			<< "3  - Delete meeting." << endl
			<< "4  - Find meeting." << endl
			<< "5  - Print calendar." << endl
			<< "Any other number - quit" << endl;

		unsigned int c;

		// if numeric value
		if (cin >> c)
		{
			switch (c) {

			case 1:
				try
				{
					regularMeeting = getMeeting<T>();
				
					calendar->addMeeting(regularMeeting);
				}
				catch (exception& ex)
				{
					cout << "\nExcepetion ! " << ex.what() << endl;
					break;
				}
				
				cout << "\nThe new meeting has been added to the calendar" << endl;
				break;

			case 2:
				try
				{
					locationMeeting = getMeetingWithLoc<T>();
					calendar->addMeeting(locationMeeting);
				}
				catch (exception& ex)
				{
					cout << "\nExcepetion ! " << ex.what() << endl;
					break;
				}
				
				cout << "\nThe new meeting has been added to the calendar" << endl;
				break;

			case 3:
				cout << "\nEnter meeting's start time : " << endl;
				startTime = getTimeValue<T>();

				hasDeleted = calendar->deleteMeeting(startTime);

				if (hasDeleted)
				{
					cout << "\nMeeting has been succesfully deleted." << endl;
				}
				else
				{
					cout << "\nMeeting was not found." << endl;
				}

				break;

			case 4:
				cout << "\nEnter meeting's start time : " << endl;
				startTime = getTimeValue<T>();
				regularMeeting = calendar->findMeeting(startTime);

				if (regularMeeting)
				{
					cout << "\nMeeting was found : " << endl;
					cout << *regularMeeting << endl;
				}
				else
				{
					cout << "\nMeeting was not found." << endl;
				}

				break;

			case 5:
				cal = new DayCalendar_t<T>(*calendar);
				calendar->deleteMeeting(8);
				cal->print();
				calendar->print();
				break;
	
			default:
				cont = false;
				break;
			}
		}
		else
		{
			// Non numeric value, quit.
			cont = false;
		}

	}
}

//====================================================


int main() {
	bool isFloat = false , cont = true;
	unsigned int c;
	while (cont) 
	{
		cout << "Choose type of calendar 0 = int, 1 = float, any other key = exit" << endl;
		
		// if numeric value
		if (cin >> c)
		{
			if (c == 1)
			{
				testMenu(new DayCalendar_t<float>());
			}
			else if ( c == 0)
			{
				testMenu(new DayCalendar_t<int>());
			}
			cont = false;
		}
		else
		{
			// Non numeric value, quit.
			cont = false;
		}
	}

	return 0;
}

