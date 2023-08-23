#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
deque<string> dq;
int idx;

bool check(string s) {
    for (int i = 0; i < dq.size(); i++) {
        if (dq[i] == s) {
            idx = i;
            return true;
        }
    }
    return false;
}

string transform(string s) {
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 97) temp += s[i] - 32;
        else temp += s[i];
    }
    return temp;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for (auto var : cities) {
        string s = transform(var);
        if (!check(s)) answer += 5;
        else {
            answer += 1;
            dq.erase(dq.begin() + idx);
        }
        dq.push_front(s);
        if (dq.size() > cacheSize) dq.pop_back();
    }
    return answer;
}