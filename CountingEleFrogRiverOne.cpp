// CountingEleFrogRiverOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int finder(vector<int> &A, vector<int> &B, int pos)
{
	int destPosTime = -1;
	bool found_at_least_once = false;
	auto start_it = A.begin();
	 
	cout << "\n";
	while (start_it != A.end()) {
		start_it = std::find(start_it, A.end(), pos);
		if (start_it != A.end()) {
			auto const timePos = std::distance(A.begin(), start_it);
			std::cout << "FOUND LEAF: "<<pos<<" AT : " << timePos << '\n';
			if (destPosTime == -1)
			{
				destPosTime = timePos;	
			}		
			++start_it;
			found_at_least_once = true;
		}
	}
	std::cout << "Least AT : " << pos << " AT : " << destPosTime << '\n';
	if (found_at_least_once == true)
	{
		//if()
		return destPosTime;
	}

	if (!found_at_least_once) {
		//std::cout << "NOT FOUND" << '\n';
		return -1;
	}
}
//int solution(int X, vector<int> &A)
//{
//	int crossTime = -1;
//	vector<int> B;
//
//	for (int pos = 1; pos < X + 1; ++pos)
//	{
//		crossTime = finder(A,B,pos);
//	}
//	return crossTime;
//}
int solution(int X, vector<int> &A)
{
	int pos = 1;  
	vector<int> B;

	for (int i = 0; i < A.size(); ++i)
	{
		
		auto it = std::find(A.begin(), A.end(), pos);

		if (it != A.end())
		{
			auto const timePos = std::distance(A.begin(), it);
			cout << "B Value: ";
			B.push_back(timePos);
			cout << B[i] << endl;
			if (pos < X)
			{
				pos++;
				cout << "Pos Value: " << pos << endl;
			}
			else
			{
				break;
			}
				
		}
		else
		{
			return -1; //did not find element cant cross river
		}
	}
	cout << "B Size: " << B.size()<<endl;

	if (B.size() == X) //found all elements
	{
		std::sort(B.begin(), B.end(), std::greater<int>());
		cout << "B Value: " << B[0] << endl;
		return B[0];
	}

}


int main()
{
	//vector<int> A = {1,3,1,4,2,3,5,4};
	vector<int> A = { 5,3,1,4,2,3,5,4,1};
	
	int crossTime = -1;

	crossTime = solution(5, A);	

	cout <<"\n"<< "The time for the frog to reach: " << crossTime << " secs" << endl;

    return 0;
}

