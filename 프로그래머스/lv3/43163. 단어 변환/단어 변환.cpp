#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int visited[51];

int check(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) cnt++;
    }
    return cnt;
}

bool visit_check(int e) {
    for (int i = 0; i < e; i++) {
        if (!visited[i]) return true;
    }
    return false;
}

int go(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q;
    q.push({begin, 0});

    while(q.size()) {
        auto s = q.front();
        q.pop();

        for (int i = 0; i < words.size(); i++) {
            if (!visited[i] and check(s.first, words[i]) == 1) {
                if (words[i] == target) return s.second + 1;
                q.push({words[i], s.second + 1});
                visited[i] = 1;
            }
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = go(begin, target, words);
    return answer;
}