#include "TestVectorMyJosephus.h"
#include "VectorMyJosephus.h"

VectorMyJosephus::~VectorMyJosephus()
{
	for (int i = 0; i < size; i++)
	{
		circ.pop_back();
	}
};

void VectorMyJosephus::init(int N, int M)
{
	this->N = N;
	this->M = M;
}

void VectorMyJosephus::clear()
{
	circ.clear();
}

double VectorMyJosephus::getAvgElimTime()
{
	return AvgElimTime;
}

int VectorMyJosephus::currentSize() const
{
	cout << "Number of people still playing: " << size << endl;
	return size;
}

bool VectorMyJosephus::isEmpty()
{
	return circ.empty();
}

void VectorMyJosephus::printAll()
{
	vector<Person>::iterator itr = circ.begin();
	cout << endl << "Players left - " << endl;
	while (itr != circ.end())
	{
		cout << "Player at Postion: " << itr->getPosition() << endl;
		itr++;
	}
}
void VectorMyJosephus::PlayGame(void)
{
	vector<Person>::iterator itr = circ.begin();
	//round counter
	int i = 0;
	TestVectorMyJosephus ElimPeople;
	clock_t start = clock();
	vector<double> Avgtime;
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
			cout << "At the end of round " << i << ":";
			printAll();
			system("pause");
			system("cls");
		}
		else
		{
			itr++;
			Passes--;
		}

	}
	double sum = 0.0; int j = 1.0;
	vector<double>::iterator Titr = Avgtime.begin();
	for (; Titr != Avgtime.end(); Titr++, j++)
	{
		sum += *Titr;
	}
	AvgElimTime = (double)(sum / j);
	system("pause");
	system("cls");
	printAll();
	ElimPeople.PrintAll();
}