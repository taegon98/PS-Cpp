#include <string>
#include <vector>
#include <queue>

using namespace std;
int visited[1000001];

int bfs(int x, int y, int n) {
    queue<int> q;
    q.push(x);
    visited[x] = 0;
    
    while(q.size()) {
        int temp = q.front();
        q.pop();
        
        if (temp == y) {
            return visited[temp];
        }
        
        for (auto var : {temp + n, temp * 2, temp * 3}) {
            if (var <= y and !visited[var]) {
                q.push(var);
                visited[var] = visited[temp] + 1;
            }
        }
    }
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
    answer = bfs(x, y, n);
    return answer;
}