#include <string>
#include <vector>
#include <queue>
using namespace std;
char arr[101][101];
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int r, c, sy, sx, ey, ex, ly, lx;

int go(int y, int x, int des_y, int des_x) {
    int visited[101][101] = { 0 };
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    
    while(q.size()) {
        int t_y = q.front().first;
        int t_x = q.front().second;
        q.pop();
        
        if (t_y == des_y and t_x == des_x) {
            return visited[t_y][t_x] - 1;
        }
        
        for (int i = 0; i < 4; i++) {
            int ny = t_y + dy[i];
            int nx = t_x + dx[i];
            
            if (ny < 0 or nx < 0 or ny >= r or nx >= c) continue;
            if (visited[ny][nx] or arr[ny][nx] == 'X') continue;
            visited[ny][nx] = visited[t_y][t_x] + 1;
            q.push({ny, nx});
        }
    }
    
    return 0;
}

int solution(vector<string> maps) {
    int answer = 0;
    r = maps.size();
    c = maps[0].size();
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = maps[i][j];
            if (arr[i][j] == 'L') {
                ly = i; lx = j;
            }
            if (arr[i][j] == 'S') {
                sy = i; sx = j;
            }
            if (arr[i][j] == 'E') {
                ey = i; ex = j;
            }
        }
    }
    
    answer = go(sy, sx, ly, lx);
    if (!answer) answer = -1;
    else {
        int temp = go(ly, lx, ey, ex);
        if (!temp) answer = -1;
        else answer += temp;
    }
    
    return answer;
}