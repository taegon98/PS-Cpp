#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M, x_1, y_1, x_2, y_2, y, x, ny, nx, ret;
bool ok = false;
char graph[304][304];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int sy, int sx) {
	bool visited[304][304];
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		y = q.front().first; x = q.front().second;
		q.pop();
		if (y == x_2 and x == y_2) {
			ok = true;
			return;
		}

		for (int d = 0; d < 4; d++) {
			ny = y + dy[d];
			nx = x + dx[d];
			if (ny == x_2 and nx == y_2) {
				ok = true;
				return;
			}
			if (ny >= 1 and ny <= N and nx >= 1 and nx <= M and !visited[ny][nx]) {
				visited[ny][nx] = true;
				if (graph[ny][nx] == '1') graph[ny][nx] = '0';
				else if (graph[ny][nx] == '0') q.push({ ny,nx });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> x_1 >> y_1 >> x_2 >> y_2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> graph[i][j];
	}
	while (1) {
		ret++;
		bfs(x_1, y_1);
		if (ok) break;
	}
	cout << ret;
}