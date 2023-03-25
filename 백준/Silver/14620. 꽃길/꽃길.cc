#include <iostream>
using namespace std;

int N, ny, nx, ret = 987654321;
int graph[11][11];
int visited[11][11];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void go(int y, int x, int depth, int cost) {
	if (depth == 3) {
		ret = min(ret, cost);
		return;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			bool ok = true;
			if (visited[i][j]) continue;
			for (int d = 0; d < 4; d++) {
				ny = i + dy[d];
				nx = j + dx[d];
				if (ny<1 or ny>N or nx<1 or nx>N or visited[ny][nx]) {
					ok = false;  break;
				}
			}
			if (ok) {
				int tmp = graph[i][j];
				for (int d = 0; d < 4; d++) {
					ny = i + dy[d]; nx = j + dx[d];
					visited[ny][nx] = 1;
					tmp += graph[ny][nx];
				}
				visited[ny][nx] = 1;
				go(ny, nx, depth + 1, cost + tmp);
				for (int d = 0; d < 4; d++) {
					ny = i + dy[d]; nx = j + dx[d];
					visited[ny][nx] = 0;
				}
				visited[ny][nx] = 0;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> graph[i][j];
	}
	go(1, 1, 0, 0);
	cout << ret;
}