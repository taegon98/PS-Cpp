#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<int> v;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') v.push_back('(');
        else {
            if (!v.size()) {
                answer = false;
                break;
            }
            v.pop_back();
        }
    }
    if (v.size()) answer = false;
    return answer;
}