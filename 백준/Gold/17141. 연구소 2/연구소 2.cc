#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, arr[51][51], ret = 987654321;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
vector<pair<int, int>> v1, v2;

int check() {
    queue<pair<int, int>> q;
    int temp_ret = 0;
    int visited[51][51] = { 0 };

    for (auto var : v2) {
        visited[var.first][var.second] = 1;
        q.push({ var.first, var.second });
    }

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 or nx < 0 or ny >= N or nx >= N) continue;
            if (visited[ny][nx] or arr[ny][nx] == 1) continue;
            q.push({ ny,nx });
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1) continue;
            if (!visited[i][j]) return -1;
            else temp_ret = max(temp_ret, visited[i][j]);
        }
    }
    return temp_ret;
}

void go(int depth, int idx) {

    if (depth == M) {
        int temp = check();
        if (temp != -1) {
            ret = min(ret, temp - 1);
        }
        return;
    }

    for (int i = idx; i < v1.size(); i++) {
        v2.push_back({ v1[i].first, v1[i].second });
        go(depth + 1, i + 1);
        v2.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) v1.push_back({ i,j });
        }
    }

    go(0, 0);
    if (ret == 987654321) cout << -1;
    else cout << ret;
}