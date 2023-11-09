#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, arr[101][71], visited[101][71], ret;
int dy[] = { -1,-1,-1,0,1,1,1,0 }, dx[] = { -1,0,1,1,1,0,-1,-1 };
vector<pair<int, int>> v;

bool check(int n) {
    for (auto var : v) {
        for (int i = 0; i < 8; i++) {
            int y = var.first + dy[i];
            int x = var.second + dx[i];

            if (y < 0 or x < 0 or y >= N or x >= M) continue;
            if (arr[y][x] > n) return false;
        }
    }
    return true;
}

void go(int r, int c) {
    v.clear();

    queue<pair<int, int>> q;
    q.push({ r,c });
    v.push_back({ r,c });
    visited[r][c] = 1;

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 or nx < 0 or ny >= N or nx >= M or visited[ny][nx]) continue;
            if (arr[ny][nx] == arr[y][x]) {
                visited[ny][nx] = 1;
                q.push({ ny, nx });
                v.push_back({ ny,nx });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue;
            go(i, j);
            if (check(arr[i][j])) ret++;
        }
    }
    cout << ret;
}