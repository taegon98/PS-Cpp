#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int arr[101][101], visited[101][101];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int r, c, answer;

int go(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 1;
    
    while(q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (y == r and x == c) {
            return visited[y][x];
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny <= 0 or nx <= 0 or ny > r or nx > c or visited[ny][nx]) continue;
            if (!arr[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    r = maps.size(), c = maps[0].size();
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            arr[i + 1][j + 1] = maps[i][j];
    }
    
    answer = go(1, 1);
    return answer;
}