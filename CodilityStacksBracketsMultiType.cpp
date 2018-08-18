// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <string>
using namespace std;

#include <bits/stdc++.h>

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
 stack<char> bracket_stack{};
    
    auto checkBrackets = [](char ch) {
        switch(ch)
        {
            case '{':return '}';
            case '[':return ']';
            case '(':return ')';
        }
    };
    
    for(int i=0;i<S.length();++i)   
    {
        if(S[i]=='{' || S[i]=='[' || S[i]=='(')//opening brackets
        {
            bracket_stack.push(S[i]);
        }
        else if(S[i]=='}' || S[i]==']' || S[i]==')') //closing brackets
        {
            char openBracket = bracket_stack.top();
            if(S[i] == checkBrackets(openBracket))
            {
                if(!bracket_stack.empty())
                {
                    bracket_stack.pop();
                }
            }
        }
        else
        {
            return 0;
        }
    }
    if(bracket_stack.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}