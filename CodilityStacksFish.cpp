// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//if the below header file does not work then use above includes
#include<bits/stdc++.h> 

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    stack <int> downStream;
    int count=0;

    for(int i=0;(size_t)i<A.size();++i)//auto i:A) 
    {
        int curFish = A[i];
        int curFlow = B[i];

        if(curFlow ==1)//downstream
        {
            downStream.push(A[i]);
        }

        if(!downStream.empty() && curFlow ==0)//upstream
        {
            //std::cout<<"Stack top: "<<downStream.top()<<endl;
            //std::cout<<"Cur fish: "<<curFish<<endl;
            while(!downStream.empty() && curFish > downStream.top())
            {
                //std::cout<<"Popped element: "<<downStream.top()<<endl;
                downStream.pop();//eat the fish
            }
        }
        if(downStream.empty() && curFlow ==0)//nothing to eat
        {
            count++;
        }
    }
    //std::cout<<"Stack size: "<<downStream.size()<<std::endl;
    return count+downStream.size();
}

int main()
{

	std::cout << "Fish Problem Codility - C++ !" << endl;

    vector<int> A = {4,3,2,1,5};
    vector<int> B = {0,1,0,0,0};

    //vector<int> A = {1,5,8,3,2,9};//{4,3,2,1,5};
    //vector<int> B = {1,0,1,1,1,0};//{0,1,0,0,0};

    int fishAlive = solution(A,B);

    std::cout<<"No of fish Alive: "<<fishAlive;
	return 0;
}