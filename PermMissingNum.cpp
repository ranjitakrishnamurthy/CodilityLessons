// PermMissingNum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A)
{
	int missingElement = 0;

	sort(A.begin(), A.end());

	cout << "Sorted Array: " << endl;
	for(int i=0;i<A.size();i++)
	cout<<A[i]<<endl;

	for (int loopCnt = 0; loopCnt < A.size(); ++loopCnt)
	{
		if (loopCnt + A[0] != A[loopCnt])
		{
			missingElement = loopCnt + A[0];
			return missingElement;
		}
	}

	return missingElement;
}

int main()
{
	vector<int> A;// = { 4,5,6,7,15 };
	int result = 0;
	result = solution( A);
	cout << "The Result is: " << result << endl;
    return 0;
}

