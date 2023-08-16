#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;
stack<char> s;
deque<char> dq;

bool check() {
    for (auto var : dq) {
        if (var == '{' or var == '(' or var == '[') s.push(var);
        else if (s.size() and var == '}' and s.top() == '{') s.pop();
        else if (s.size() and var == ')' and s.top() == '(') s.pop();
        else if (s.size() and var == ']' and s.top() == '[') s.pop();
        else return false;
    }
    if (s.size()) return false;
    else return true;
}

int solution(string s) {
    int answer = 0;
    for (auto var : s) dq.push_back(var);
    
    for (int i = 0; i < s.size() - 1; i++) {
        if (check()) answer++;
        dq.push_back(dq.front());
        dq.pop_front();
    } 
    return answer;
}