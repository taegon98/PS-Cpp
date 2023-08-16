#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<char> s;

bool check(string str) {
    for (auto var : str) {
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

    for (int i = 0; i < s.size() - 1; i++) {
        if (check(s)) answer++;
        s.push_back(s[0]);
        s.erase(0, 1);
    } 
    return answer;
}