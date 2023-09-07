#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int go(int n, int visited[], vector<int> v[]) {
    int cnt = 1;
    visited[n] = 1;
    for (auto var : v[n]) {
        if (!visited[var]) cnt += go(var, visited, v);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for (int i = 0; i < wires.size(); i++) {
        vector<int> v[101];
        int visited[101] = { 0 }, cnt[2] = { 0 }, idx = 0;
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;
            v[wires[j][0]].push_back(wires[j][1]);
            v[wires[j][1]].push_back(wires[j][0]);
        }
        
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            cnt[idx++] = go(i, visited, v);
        }
        answer = min(answer, abs(cnt[0] - cnt[1]));
    }
    return answer;
}