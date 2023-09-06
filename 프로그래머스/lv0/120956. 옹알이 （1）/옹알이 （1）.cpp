#include <string>
#include <vector>
#include <iostream>

using namespace std;
string str[] = {"aya", "ye", "woo", "ma"};

int go(string s) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        auto pos = s.find(str[i]);
        if (pos == string::npos) continue;
        else cnt += str[i].size();
    }
    return cnt;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (auto var : babbling) {
        int temp = go(var);
        if (temp == var.size()) answer++;
    }
    return answer;
}