#include <string>
#include <vector>
#include <iostream>
using namespace std;
int visited[10], s, answer = -987654321;

void go(int rem, vector<vector<int>> d, int cnt) {
    answer = max(answer, cnt);
    if (cnt == d.size()) {
        
        return;
    }
    
    for (int i = 0; i < s; i++) {
        if (rem < d[i][0] or visited[i]) continue;
        visited[i] = 1;
        go(rem - d[i][1], d, cnt + 1);
        visited[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    s = dungeons.size();
    go(k, dungeons, 0);
    return answer;
}