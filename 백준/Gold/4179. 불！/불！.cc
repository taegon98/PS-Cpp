#include <iostream>
#include <queue>
using namespace std;

int R, C;
char tmp;
char graph[1004][1004];
int visited_f[1004][1004] = { 0 };
int visited_p[1004][1004] = { 0 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<pair<int, int>> q_f;
queue<pair<int, int>> q_p;

bool bfs_p() {
	while (!q_p.empty()) {
		int y = q_p.front().first;
		int x = q_p.front().second;
		q_p.pop();

		if ((y == 0 or y == R - 1 or x == C - 1 or x == 0) and visited_p[y][x] >= 1) {
			cout << visited_p[y][x];
			return true;
		}

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny >= 0 and ny < R and nx >= 0 and nx < C) {
				if (graph[ny][nx] != '#' and visited_p[ny][nx] == 0) {
					int tmp = visited_p[y][x] + 1;
					if (tmp < visited_f[ny][nx] or visited_f[ny][nx] == 0) {
						q_p.push({ ny,nx });
						visited_p[ny][nx] = tmp;
					}
				}
			}
		}
	}
	return false;
}


void bfs_f() {
	while (!q_f.empty()) {
		int y = q_f.front().first;
		int x = q_f.front().second;
		q_f.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny >= 0 and ny < R and nx >= 0 and nx < C) {
				if (graph[ny][nx] != '#' and visited_f[ny][nx] == 0) {
					visited_f[ny][nx] = visited_f[y][x] + 1;
					q_f.push({ ny,nx });
				}
			}
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> tmp;
			if (tmp == 'F') {
				visited_f[i][j] = 1;
				q_f.push({ i,j });
			}
			else if (tmp == 'J') {
				visited_p[i][j] = 1;
				q_p.push({ i,j });
			}
			graph[i][j] = tmp;
		}
	}

	bfs_f();
	if (!bfs_p()) cout << "IMPOSSIBLE";
	return 0;
}