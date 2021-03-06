/*
 * Person:
 * This class encapsulates a person within the Josephus circle.
 */

#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include<ctime>

using namespace std;

class Person {

	public: 
		// Constructor:
		// Note: A person object should be created only if there is a position available for that person to occupy. 
		//		And of course, no two people can occupy the same position, and 
		//		no person can occupy more than one position at any given time.
		// ...
		explicit Person(int pos = 0) :position(pos){};

		// Destructor
		// ...
		~Person();
		
		// print the position
		void print();

		//getter
		int getPosition(void) const;

		//setter
		void setPosition(int newPos);

	private:
		int position; // position occupied by the person at any point of the game
						// Note: Because each position occupies a unique position initially, 
						// 		that initial position can also be treated as the identifier (id)
						//		or name for that person.
						//		And as the potato is passed around and people are eliminated,
						//			that id can be retained.
};
 
#endif
