// TennisTournament.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int solution(int P, int C)
{
	int matchesPossible = 0;
	int eachGame = 2;

	if (eachGame <= P)
	{
		matchesPossible = P / 2;
	}

	//Players are less,Courts are more
	if (matchesPossible < C)
	{
		return matchesPossible;
	}
	
	//Courts are less,Players are more
	if (matchesPossible > C)
	{
		return C;
	}

}
int main()
{
	int maxMatches = 0;
	int players = 5;
	int courts = 3;

	maxMatches = solution(players, courts);
	cout << "The Max matches which can be played:  " << maxMatches << endl;

    return 0;
}

