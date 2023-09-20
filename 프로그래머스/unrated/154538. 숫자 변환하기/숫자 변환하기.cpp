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
        
        if (temp > y) return -1;
        if (temp == y) {
            return visited[temp];
        }
        
        int nx = temp + n;
        if (nx <= y and !visited[nx]) {
            q.push(nx);
            visited[nx] = visited[temp] + 1;
        }
        nx = temp * 2;
        if (nx <= y and !visited[nx]) {
            q.push(nx);
            visited[nx] = visited[temp] + 1;
        }
        nx = temp * 3;
        if (nx <= y and !visited[nx]) {
            q.push(nx);
            visited[nx] = visited[temp] + 1;
        }
    }
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
    answer = bfs(x, y, n);
    return answer;
}