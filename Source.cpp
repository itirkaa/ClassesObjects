#include<iostream>

/*
Topics to be covered:
Specifying a class, creating objects, accessing class members,
defining a member function inside and outside class, access specifiers,
inline function, static data members & member functions.
Objects as function arguments, friend function, returning objects to functions.
*/

//Class: Building block of C++, leads to Object Oriented Programming
//User defined data type, holds its own data members and member functions
//Blueprint for an Object

//Object: instance of a class or a variable of a class type

//Member Functions: Functions defined inside class
//aka methods

class Date {
// private members by default
	/*
	no matter how many objects of the class are created,
	there is only one copy of the static member.
	A static member is shared by all objects of the class.
	*/
	static int m_objectCount;

	int m_year;
	int m_month;
	int m_day;

public:
	//member functions

	//setter
	void setDate(int month, int day, int year) {
		m_month = month;
		m_day = day;
		m_year = year;
	}

	//friend function
	friend void printDate(Date);

	void copyFrom(const Date& d) { 	// works fine without & tho
		// Note that we can access the private members of d directly
		m_month = d.m_month+1;
		m_day = d.m_day+1;
		m_year = d.m_year+1;
	}
};

int Date :: m_objectCount = 0;

//definition of friend funtion
void printDate(Date d) {
	d.m_objectCount++;
	std::cout << d.m_objectCount << ": " << d.m_year << "/" << d.m_month << "/" << d.m_day << std::endl;
}

//inline functions work faster than normal functions
inline void printSpace() {
	std::cout << "------------------------" << std::endl;
}

int main() {
	//Date today{ 2019, 4, 21 }; // Uniform initialization: valid in C++11
	//today.print();

	Date yesterday;
	// Membor selector operator(.): used to access member of class
	//yesterday.m_year = 2019; // can't do, because m_year is private
	//yesterday.m_month = 4;
	//yesterday.m_day = 20;
	yesterday.setDate(4, 20, 2019);
	printDate(yesterday);
	
	printSpace();
	
	Date lastday;
	lastday.copyFrom(yesterday);
	printDate(lastday);
}