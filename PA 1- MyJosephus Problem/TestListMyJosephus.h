#pragma once
#ifndef TestListMyJosephus_H
#define _TestListMyJosephus_H

#include "ListMyJosephus.h"

class TestListMyJosephus
{
public:
	explicit TestListMyJosephus() {};

	void insert(int Value);
	void PrintAll();
	void PlayGame();

private:
	list<int> Peliminated; //people eliminated
	double TimeElapsed; //total time for playing the game
	double AvgElimTime; // average elimination time which is the average for the time spent  between two consecutive eliminations. 
};


#endif