#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int r, c, y, x, ret;
char graph[54][54];
int visited[54][54];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int check() {
	int max_val = -1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			max_val = max(max_val, visited[i][j]);
		}
	}
	return max_val;
}

void bfs(int sy, int sx) {
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny >= 0 and ny < r and nx >= 0 and nx < c and !visited[ny][nx]) {
				if (graph[ny][nx] == 'L') {
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> graph[i][j];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (graph[i][j] == 'L') {
				bfs(i, j);
				ret = max(check(), ret);
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	cout << ret - 1;
	return 0;
}