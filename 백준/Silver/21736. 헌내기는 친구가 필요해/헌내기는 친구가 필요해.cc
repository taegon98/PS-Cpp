#include <iostream>
#include <queue>
using namespace std;

int N, M, visited[601][601], sy, sx, ret;
char arr[601][601];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void go(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r, c });
	visited[r][c] = 1;

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
			if (visited[ny][nx] or arr[ny][nx] == 'X') continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
			if (arr[ny][nx] == 'P') ret++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') sy = i, sx = j;
		}
	}
	go(sy, sx);
	if (!ret) cout << "TT";
	else cout << ret;
}