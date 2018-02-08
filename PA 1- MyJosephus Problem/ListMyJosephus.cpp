#include "ListMyJosephus.h"
#include "TestListMyJosephus.h"

ListMyJosephus::~ListMyJosephus()
{
	for (int i = 0; i < size; i++)
	{
		circ.pop_back();
	}
};

void ListMyJosephus::init(int N, int M)
{
	this->N = N;
	this->M = M;
}

void ListMyJosephus::clear()
{
	circ.clear();
}

double ListMyJosephus::getAvgElimTime()
{
	return AvgElimTime;
}

int ListMyJosephus::currentSize() const
{
	cout << "Number of people still playing: " << size << endl;
	return size;
}

bool ListMyJosephus::isEmpty()
{
	return circ.empty();
}

void ListMyJosephus::printAll()
{
	list<Person>::iterator itr = circ.begin();
	cout << endl << "Players left - " << endl;
	while (itr != circ.end())
	{
		cout << "Player at Postion: " << itr->getPosition() << endl;
		itr++;
	}
}
void ListMyJosephus::PlayGame(void)
{
	list<Person>::iterator itr = circ.begin();
	//round counter
	int i = 0;
	TestListMyJosephus ElimPeople;
	list<double> Avgtime;
	clock_t start = clock();
	//simulation loop
	while (this->size > 1)
	{
		//idea of circularly linked list is being implemented
		if (itr == circ.end())
		{
			itr = circ.begin();
			i++;
		}

		if (Passes == 0)
		{
			ElimPeople.insert(itr->getPosition());
			//delete the node
			//sets the itr to the next element after deleting the node it is currently pointing to
			itr = circ.erase(itr);
			clock_t end = clock();
			Avgtime.push_back((double)(end - start) / CLOCKS_PER_SEC);
			start = clock();
			//size is decremented by 1
			size--;
			//set passes to original value
			Passes = M;
			//prints the number of players still playing after each round
		//	cout << "At the end of round " << i << ":";
		//	printAll();
		//	system("pause");
		//	system("cls");
		}
		else
		{
			itr++;
			Passes--;
		}

	}
	double sum = 0.0; int j = 1;
	list<double>::iterator Titr = Avgtime.begin();
	for (; Titr != Avgtime.end(); Titr++, j++)
	{
		sum += *Titr;
	}
	AvgElimTime = sum / j;
//	system("pause");
//	system("cls");
//	printAll();
//	ElimPeople.PrintAll();
}