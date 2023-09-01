#include <string>
#include <vector>
#include <deque>
#include <map>
#include <iostream>
using namespace std;
deque<char> dq1, dq2;
map<char, int> mp;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (auto var : skill) {
        dq1.push_back(var);
        mp[var] = 1;
    }
    
    for (auto var : skill_trees) {
        bool ok = true;
        dq2 = dq1;
        for (int i = 0; i < var.size(); i++) {
            if (mp.find(var[i]) == mp.end()) continue;
            else if (dq2.front() == var[i]) {
                dq2.pop_front();
            }
            else {
                ok = false;
                break;
            }
        }
        if (ok) answer++;
    }
    return answer;
}