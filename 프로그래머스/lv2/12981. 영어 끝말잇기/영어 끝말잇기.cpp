#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int cur = 1, cnt = 1, i;
    mp[words[0]] = 1;
    char ch = words[0][words[0].size() - 1];
    
    for (i = 1; i < words.size(); i++) {
        if (ch != words[i][0]) break;
        if (mp.find(words[i]) != mp.end()) break;
        mp[words[i]] = 1;
        cur = (cur + 1) % n;
        if (cur == 0) cnt++;
        ch = words[i][words[i].size() - 1];

    }
    if (i == words.size()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(cur + 1);
        answer.push_back(cnt);
    }
    return answer;
}