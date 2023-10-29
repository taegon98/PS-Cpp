#include <iostream>
#include <queue>
using namespace std;
int M, N, ret, arr[251][251], visited[251][251];
int dy[] = { -1,-1,-1,0,1,1,1,0 };
int dx[] = { -1,0,1,1,1,0,-1,-1 };

void go(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visited[r][c] = 1;

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 or nx < 0 or ny >= M or nx >= N) continue;
			if (visited[ny][nx] or arr[ny][nx] == 0) continue;

			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] and arr[i][j] == 1) {
				ret++;
				go(i, j);
			}
		}
	}
	cout << ret;
}