#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define TRUE    1
#define FALSE   0


const int SIZE = 12;
const int columns = 7;
const int rows = 5;

string month_Name[SIZE] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int Num_of_days_in_month[SIZE] = { 31,0,31,30,31,30,31,31,30,31,30,31 };

string day_Name[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
int dayNumber[7] = { 1, 2, 3, 4, 5, 6, 7 };

void LeapYear(int);
void showMyCalendar(string, int, int[][columns], int, int[], string[], string);
void matchDayName(string, string[]);
void matchMonthName(string, string[]);

//2_D Array 
int month[rows][columns] = { {1, 2, 3, 4, 5, 6, 7},
						   {8, 9, 10, 11, 12, 13, 14},
						   {15, 16, 17, 18, 19, 20, 21},
						   {22, 23, 24, 25, 26, 27, 28},
						   {29, 30, 31, 0, 0, 0, 0} };



int main() {
	string user_Choice;
	string GET_DAY;
	int GET_YEAR;

	cout << "Enter the name of a Month> ";
	getline(cin, user_Choice);

	matchMonthName(user_Choice, month_Name);

	while (user_Choice != "Stop" && user_Choice != "stop")
	{
		cout << "\nEnter the year> ";
		cin >> GET_YEAR;
		cout << endl;
		LeapYear(GET_YEAR);

		cout << "\nEnter the day the month starts> ";
		cin >> GET_DAY;
		matchDayName(GET_DAY, day_Name);
		cout << "\n";
		showMyCalendar(user_Choice, GET_YEAR, month, rows, dayNumber, month_Name, GET_DAY);

		cout << "\nEnter the name of a month or enter stop to quit>";
		cin.ignore();
		getline(cin, user_Choice);
		matchMonthName(user_Choice, month_Name);

	}

	system("pause");
	return 0;
}


// Definition Of The Function matchMonthName Which Test The Input Of The User 
void matchMonthName(string choice, string monthName[]) {

	int found = 0;
	int a = 0;
	for (a = 0; a < 7 && !found; a++)
	{
		if (monthName[a] == choice || choice == "stop" || choice == "Stop")
		{
			found = 1;
		}
	}   // end for loop
	if (found)
	{
		cout << endl;
	}
	else
	{
		cout << "ERROR: The day " << choice << " was not found...please again!" << endl << endl;
	}
}

// Definition Of The Function matchDayName Which Test The Input Of The User:
void matchDayName(string GET_DAY, string dayOfWeek[]) {

	int found = 0;
	int a = 0;
	for (a = 0; a < 7 && !found; a++)
	{
		if (dayOfWeek[a] == GET_DAY)
		{
			found = 1;
		}
	}   // end for loop
	if (found)
	{
		cout << endl;
	}
	else
	{
		cout << "ERROR: The day " << GET_DAY << " was not found...please again!" << endl << endl;
	}
}

// To Detemines If The Year is Leap Year Or Not , We Define The Function LeapYear Like This!:
void LeapYear(int GET_YEAR)
{

	if (GET_YEAR % 4 == FALSE && GET_YEAR % 100 != FALSE || GET_YEAR % 400 == FALSE)
	{
		Num_of_days_in_month[1] = 29;
	}
	else
	{
		Num_of_days_in_month[1] = 28;

	}
}

// We Define The (showMyCalendar) Function Which Formats The Calendar As Required! 
void showMyCalendar(string choice, int GET_YEAR, int month[][columns], int rows, int dayNumber[], string monthName[], string GET_DAY)
{
	int days;
	int numDays = 0;
	int start_day = 0;

	//In The Top Of Calendar , We Write The Month Name And Year :
	cout << "\t\t" << choice << "\t\t" << GET_YEAR << "\n";

	//Week Day Name:
	cout << "SUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n";

	//((Pararlle Array)) When User Entier The Month Name, Match It To The Appropriate Number Of Days:
	for (int count = 0; count < SIZE; count++)
	{
		if (choice == monthName[count])
		{
			numDays += Num_of_days_in_month[count];
		}
	}

	//((Pararlle Array)) When User Entier The Day Name, And Match It To The Proper Day Number: 
	for (int c = 0; c < 7; c++)
	{
		if (GET_DAY == day_Name[c])
		{
			start_day += dayNumber[c];
		}
	}

	//To Sets The Position For The Starting Day. We use This Loop:
	for (int i = 0; i < start_day; i++)
	{
		cout << "\t";

	}

	//To Display The Days. We Use This Loop:
	for (month[rows][columns] = (1 + start_day); month[rows][columns] <= (numDays + start_day); month[rows][columns]++)
	{

		cout << (month[rows][columns] - start_day) << "\t";
		if (month[rows][columns] % 7 == 0) {
			cout << endl;

		}
	}

	cout << endl;

}