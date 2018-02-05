#include "Person.h"

Person::~Person()
{}

void Person::print()
{
	cout << "Position : " << position << endl;
}

int Person::getPosition(void) const
{
	return position;
}

void Person::setPosition(int newPos)
{
	position = newPos;
}

