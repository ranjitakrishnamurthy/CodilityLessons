// OddOccuranceArrayPrasanth.cpp : Defines the entry point for the console application.
//Score: 66%

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> &A)
{
	int result = 0;
	vector<int> B = A;

	//cout << "The contents of B Array:" << endl;
	int i = 0, j = i+1;
	for (int loopcnt = 0; loopcnt <= B.size(); loopcnt++)
	{
	//	cout << B[loopcnt]<<endl;
		if (B.size() == 1)
		{
			result = B[0];
			return result;
		}
		
		if (B[i] == B[j])
		{
			B.erase(B.begin() + i);
			B.erase(B.begin() + j-1);
			i = 0; 
			j = i+1;
			loopcnt = 0;
		}
		else
		{
			if (j < B.size() - 1)
			{
				j = j + 1;
			}
			else
			{
			//	i = i + 1;
				result = B[i];
				break;
			}			
		}
		
	}

	
	return result;
}

int main()
{
	vector<int> A = { 9,9,9,3,3,9,7,8,8};

	int result = solution(A);
	cout << "The result is" << result << endl;

    return 0;
}

