#include <iostream>
#include <string>
#include <vector>
//#include<bits/stdc++.h> 
#include <stack>
using namespace std;


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
//if the below header file does not work then include the above //header files
#include<bits/stdc++.h> 

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    //std::cout<<"String is: "<<S<<std::endl;

    stack<char> par_stack {};

    for(int i=0;i<S.length();++i)
    {
        //std::cout<<"Stack value at: "<<S[i]<<std::endl;
        if(S[i] == '(')
        {
            par_stack.push(S[i]);
            //std::cout<<"Stack size: "<<par_stack.size()<<std::endl;
        }
        else if(S[i]==')')
        {
            if(!par_stack.empty())
            {
                par_stack.pop();      
                //std::cout<<"Stack size: "<<par_stack.size()<<" after pop"<<std::endl; 
            }     
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    if(par_stack.empty())
    {
        return 1;
    }
    return 0;
}

int main()
{

	std::cout << "Codility Nesting C++ !" << endl;
    string S = "(()(())())";
    //if 1: properly nested,0 improper
    int result = solution(S);
    std::cout<<"The result: "<<result<<std::endl;

	return 0;
}
