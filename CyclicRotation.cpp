// CyclicRotation.cpp : Defines the entry point for the console application.
//Score:75%

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool pass = false;

void displayVector(vector<int> &A)
{
	
	for (int loopcnt = 0; loopcnt < A.size(); ++loopcnt)
	{
		cout << A[loopcnt] << "\t";
	}
}
void inputVector(vector<int> &A)
{
	int N = 0;

	cout << "Enter the number of elements to input" << endl;
	cin >> N;

	A.resize(N);

	cout << "Enter the contents of Array" << endl;

	for (int loopcnt = 0; loopcnt < A.size(); ++loopcnt)
	{
		cin >> A[loopcnt];
	}
}
bool checkers(vector<int> &A, int K, bool &pass)
{
	if (A.empty())
	{
		pass = false;
		return pass;
	}
	if (K >= A.size())
	{
		pass = false;
		return false;
	}

	return true;
}
vector<int> solution(vector<int> &A, int K)
{
	//bool pass = checkers(A, K);

	bool test = checkers(A, K, pass);

	if (pass == true)
	{
		//Rotate the array by input times specified	
		std::rotate(A.begin(), A.end() - K, A.end());
	}
	return A;
}

int main()
{
	vector<int> A;
	int K =0;
	
	inputVector(A);

	cout << "Enter the Rotation times required" << endl;
	cin >> K;
	
	cout << "The contents of array before rotation is:" << endl;
	displayVector(A);

	solution(A, K); 

	if (pass == true)
	{
		cout << "\n The contents of array after rotation is:" << endl;
		displayVector(A);
	}
	else
	{
		cout << "Cannot be processed" << endl;
	}
	
    return 0;
}

