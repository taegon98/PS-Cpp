#include <iostream>
#include <vector>
using namespace std;
int N, visited[6][6];
char arr[6][6];
vector<pair<int, int>> t, v;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

bool check() {
    for (auto var : t) {
        for (int i = 0; i < 4; i++) {
            int y = var.first;
            int x = var.second;
            while (1) {
                y += dy[i];
                x += dx[i];

                if (y < 0 or x < 0 or y >= N or x >= N) break;
                if (arr[y][x] == 'O') break;
                if (arr[y][x] == 'S') return false;
            }
        }
    }
    return true;
}

void go(int depth, int idx) {

    if (depth == 3) {
        if (check()) {
            cout << "YES";
            exit(0);
        }
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        if (visited[v[i].first][v[i].second]) continue;
        visited[v[i].first][v[i].second] = 1;
        arr[v[i].first][v[i].second] = 'O';
        go(depth + 1, i + 1);
        visited[v[i].first][v[i].second] = 0;
        arr[v[i].first][v[i].second] = 'X';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'T') t.push_back({ i,j });
            else if (arr[i][j] == 'X') v.push_back({ i,j });
        }
    }

    go(0, 0);
    cout << "NO";
}