#include "TestListMyJosephus.h"
#include "ListMyJosephus.h"

void TestListMyJosephus::insert(int Value)
{
	Peliminated.push_back(Value);
}

void TestListMyJosephus::PrintAll()
{
	list<int>::iterator itr = Peliminated.begin();
	cout << "Players eliminated: {";
	while (itr != Peliminated.end())
	{
		cout << *itr << ", ";
		itr++;
	}
	cout << "} " << endl;
}

void TestListMyJosephus::PlayGame()
{
	int N = 0, M = 0;
	//prompting the user
	cout << "Please enter number of Players Playing(N): " << endl;
	cin >> N;
	cout << "Please enter the interval of elimination(M): " << endl;
	cin >> M;
//	N = 1024;
//	M = 1024;
	ListMyJosephus testJosephus(N, M);
	clock_t start = clock();
	testJosephus.PlayGame();
	clock_t end = clock();
	TimeElapsed = (double)(end - start) / CLOCKS_PER_SEC;
	AvgElimTime = testJosephus.getAvgElimTime();
	cout << "Total Game Run Time: " << TimeElapsed << endl;
	cout << "Average Elimination Time: " << AvgElimTime << endl;

}
