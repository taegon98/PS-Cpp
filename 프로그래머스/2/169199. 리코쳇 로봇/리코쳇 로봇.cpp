#include <string>
#include <vector>
#include <queue>

using namespace std;

char arr[101][101];
int visited[101][101];
int r, c, sy, sx, ey, ex;
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

void go() {
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    
    while(q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (y == ey and x == ex) return;
        
        for (int i = 0; i < 4; i++) {
            int ny = y;
            int nx = x;
            
            while(1) {
                int ty = ny + dy[i];
                int tx = nx + dx[i];
                
                if (ty >= 0 and tx >= 0 and ty < r and tx < c and 
                    arr[ty][tx] != 'D') {
                    ny = ty;
                    nx = tx;
                } 
                else break;
            }
            
            if (visited[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
}

int solution(vector<string> board) {
    int answer = 0;
    r = board.size();
    c = board[0].size();
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = board[i][j];
            if (arr[i][j] == 'R') {
                sy = i;
                sx = j;
            }
            if (arr[i][j] == 'G') {
                ey = i;
                ex = j;
            }
        }
    }
    
    go();
    answer = visited[ey][ex] - 1;
    
    return answer;
}