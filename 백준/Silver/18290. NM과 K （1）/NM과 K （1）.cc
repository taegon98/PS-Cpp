#include <iostream>
using namespace std;
int N, M, K, ret = -987654312, arr[11][11], visited[11][11];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void go(int depth, int tot) {

    if (depth == K) {
        ret = max(ret, tot);
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j]) continue;

            visited[i][j]++;

            for (int k = 0; k < 4; k++) {
                int y = i + dy[k];
                int x = j + dx[k];

                if (y < 0 or x < 0 or y >= N or x >= M) continue;
                visited[y][x]++;
            }
            go(depth + 1, tot + arr[i][j]);

            visited[i][j]--;

            for (int k = 0; k < 4; k++) {
                int y = i + dy[k];
                int x = j + dx[k];

                if (y < 0 or x < 0 or y >= N or x >= M) continue;
                visited[y][x]--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    go(0, 0);
    cout << ret;
}