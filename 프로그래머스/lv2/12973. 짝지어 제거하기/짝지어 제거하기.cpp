#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 1;
    stack<char> _stack;
    
    for (int i = 0; i < s.size(); i++) {
        if (_stack.empty()) _stack.push(s[i]);
        else if (_stack.top() != s[i]) _stack.push(s[i]);
        else if (_stack.top() == s[i]) _stack.pop();
    }
    if (_stack.size()) answer = 0;
    else answer = 1;

    return answer;
}