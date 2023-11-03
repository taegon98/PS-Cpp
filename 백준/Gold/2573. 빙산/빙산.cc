#include <iostream>
#include <queue>
using namespace std;
int N, M, arr[301][301], ret;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void go() {
	int temp[301][301] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j]) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
					if (arr[ny][nx]) continue;
					temp[i][j]++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = max(0, arr[i][j] - temp[i][j]);
		}
	}
}

int check(int r, int c, int visited[301][301]) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visited[r][c] = 1;

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
			if (!arr[ny][nx] or visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		ret++;
		go();
		int cnt = 0;
		int visited[301][301] = { 0 };
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] and !visited[i][j]) {
					cnt += check(i, j, visited);
				}
			}
		}
		if (cnt >= 2) {
			cout << ret;
			return 0;
		}
		else if (cnt == 0) {
			cout << 0;
			return 0;
		}
	}
}