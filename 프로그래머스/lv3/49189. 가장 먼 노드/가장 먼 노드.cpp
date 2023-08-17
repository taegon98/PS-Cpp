#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> v[20001];
int visited[20001];

void go(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    
    while(q.size()) {
        int temp = q.front();
        q.pop();
        
        for (auto var : v[temp]) {
            if (visited[var]) continue;
            visited[var] = visited[temp] + 1;
            q.push(var);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    go(1);
    
    int max_val = *max_element(visited, visited + n);
    for (int i = 1; i <= n; i++) {
        if (max_val == visited[i]) answer++;
    }
    
    return answer;
}