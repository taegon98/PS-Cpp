#include <string>
#include <vector>
using namespace std;
vector<int> v[201];
int visited[201];

void go(int n) {
    for (auto var : v[n]) {
        if (visited[var]) continue;
        visited[var] = 1;
        go(var);
    }    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (i == j or !computers[i][j]) continue;
            v[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            go(i);
            answer++;
        }
    }
    return answer;
}