#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> mp1, mp2;

void split(string s1) {
    char delimiter = ',';
    int idx;
    string s2 = "";
    vector<int> v;
    
    while((idx = s1.find(delimiter)) != -1) {
        string temp = s1.substr(0, idx);
        s1 = s1.substr(idx + 1);

        s2 = "";
        for (auto var : temp) {
            if (isdigit(var)) s2 += var;
        }
        v.push_back(stoi(s2));
    }
    s2 = "";
    for (auto var : s1) {
        if (isdigit(var)) s2 += var;
    }
    v.push_back(stoi(s2));
    for (auto var : v) mp1[var]++;
}

vector<int> solution(string s) {
    vector<int> answer;
    char delimiter = '}';
    int idx;
    while((idx = s.find(delimiter)) != -1) {
        split(s.substr(0, idx));
        if (s[idx + 1] == '}') break;
        s = s.substr(idx + 2);
    }
    
    for (auto var : mp1) {
        mp2[var.second] = var.first;
    }
    for (auto var : mp2) answer.push_back(var.second);

    reverse(answer.begin(), answer.end());
    return answer;
}