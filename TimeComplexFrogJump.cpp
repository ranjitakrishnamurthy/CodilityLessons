// TimeComplexFrogJump.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int solution(int X, int Y, int D)
{
	int calc = (Y - X);
	calc = calc % D;
	cout << "mod: "<<calc;

	int step = 0;
	step = (Y - X) / D;
	if (calc > 0)	{
		
		step = step + 1;
	}

	return step;
}

int main()
{
	int step =solution(10, 70, 30);
	cout << "the num of steps: " << step<<endl;
    return 0;
}

