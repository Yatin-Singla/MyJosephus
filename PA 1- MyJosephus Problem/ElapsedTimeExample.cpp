/*
* Name: Yatin Singla
* Programming Assignment: 1
* Date: 3rd February 2018
* Description: My Josephus Problem
*
*/


//is an example code that shows how to calculate processing time in C++. 

/*
* This program demonstrates how to calculate the actual
* processing time of a part of your program, say the
* execution time of function f(). The program uses the
* function clock(), the clock_t type, and the constant
* CLOCKS_PER_SEC defined in the C++ standard library "ctime".
*
*	Note: You can also use C's gettimeofday() function for timing, instead of this.
*/

// be sure to include <ctime>
#include<ctime>
#include<iostream>
#include "Person.h"
#include "VectorMyJosephus.h"
#include "ListMyJosephus.h"
#include "TestVectorMyJosephus.h"
#include "TestListMyJosephus.h"
using namespace std;


int main(int argc, char *argv[]) {

	int choice = 0;
	cout << "Please enter your choice of data structure for simulation:-" << endl;
	cout << "1. List" << endl;
	cout << "2. Vector" << endl;
	cin >> choice;
//	choice = 2;
	/*
	* We use the clock() program in library <ctime>. Program clock()
	* returns the number of clock ticks elapsed since the process
	* starts. The number of clock ticks is represented by type clock_t.
	*
	* If you wonder why we don't use time(), it's because time()
	* returns a value with a precision only to seconds.
	*/
	clock_t start = clock();
	/* record the number of elapsed ticks before calling f() */
	if(choice == 1)
	{ 
		TestListMyJosephus TestList;
		TestList.PlayGame();
	}
	else
	{
		// ---> call f() here <---
		TestVectorMyJosephus TestVector;
		TestVector.PlayGame();
		/* record the number of elapsed ticks after calling f() */
		
	}
	clock_t end = clock();
	/*
	* The number of ticks elapsed during the f() function call
	* can be calculated by (end - start). The constant
	* CLOCKS_PER_SEC specifies the relation between a clock tick
	* and a second (i.e. clock ticks per second). Therefore, dividing
	* (end - start) by CLOCKS_PER_SEC will give you the elapsed
	* time in seconds.
	*/
	cout << "CPU elapsed time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;
		
	return 0;
}

/* A way to improve the precision of measurement is to start
* timing right after the clock ticks and also measure for many
* times and get the average value.

// Wait for the clock to tick and record the start time
clock_t k = clock();
clock_t start;
do start = clock();
while (start == k);

// ---> call f() here <---

clock_t end=clock();

cout << "CPU elapsed time in seconds: "
<<(double)(end - start)/CLOCKS_PER_SEC <<endl;

* Reference:
* A program described in	B. Stroustrup: Wrapping C++ Member Function Calls
* "The C++ Report" June 2000
* http://www.research.att.com/~bs/wrap_code.cpp
*/
