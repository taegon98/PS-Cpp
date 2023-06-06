#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    stack<int> s;
    vector<int> answer;
    deque<int> dq;
    for (auto var : arr) {
        if (s.empty() or s.top() != var) s.push(var);
    }
    while (s.size()) {
        answer.push_back(s.top()); s.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}