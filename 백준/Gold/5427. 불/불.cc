#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int T, W, H, sy, sx, visited[1001][1001], v[1001][1001] = { 0 };
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
char arr[1001][1001];
deque<pair<int, int>> fire;

void go1() {

    while (fire.size()) {
        deque<pair<int, int>> temp;

        for (auto var : fire) {
            
            for (int i = 0; i < 4; i++) {
                int y = var.first + dy[i];
                int x = var.second + dx[i];

                if (y < 0 or x < 0 or y >= H or x >= W) continue;
                if (arr[y][x] == '#' or arr[y][x] == '*') continue;

                visited[y][x] = visited[var.first][var.second] + 1;
                temp.push_back({ y,x });
                arr[y][x] = '*';
            }
        }
        fire = temp;
    }
}

int bfs(int r, int c) {
    

    deque<pair<int, int>> q;
    q.push_back({ r, c });
    v[r][c] = 1;

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop_front();

        if (y == 0 or x == 0 or y == H - 1 or x == W - 1) {
            return v[y][x];
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 or nx < 0 or ny >= H or nx >= W) continue;
            if (v[ny][nx] or arr[ny][nx] == '#') continue;
            if (arr[ny][nx] == '*' and visited[ny][nx] <= v[y][x]) continue;

            v[ny][nx] = v[y][x] + 1;
            q.push_back({ ny, nx });
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> W >> H;

        fire.clear();
        memset(visited, 0, sizeof(visited));
        memset(v, 0, sizeof(v));

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') sy = i, sx = j;
                if (arr[i][j] == '*') fire.push_back({ i,j });
            }
        }

        go1();
        int temp = bfs(sy, sx);
        if (temp != -1) cout << temp << "\n";
        else cout << "IMPOSSIBLE\n";
    }
}