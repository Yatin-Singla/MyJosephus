#pragma once
#ifndef TestVectorMyJosephus_H
#define _TestVectorMyJosephus_H

#include "VectorMyJosephus.h"

class TestVectorMyJosephus
{
public:
	explicit TestVectorMyJosephus() {};

	void insert(int Value);
	void PrintAll();
	void PlayGame();


private:
	vector<int> Peliminated; //people eliminated
	double TimeElapsed; //total time for playing the game
	double AvgElimTime; // average elimination time which is the average for the time spent  between two consecutive eliminations. 
};
#endif // !TestVectorMyJosephus_H
