#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int R, C, x, y, nx, ny, ret;
bool ok = false;
char tmp;
char graph[1504][1504];
int visited[1504][1504];
int visited_s[1504][1504];
vector<pair<int, int>> v;
queue<pair<int, int>> q;
queue<pair<int, int>> swan;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> tmp;
			if (tmp == 'L') v.push_back({ i,j });
			if (tmp != 'X') q.push({ i,j });
			graph[i][j] = tmp;
		}
	}
	swan.push({ v[0].first, v[0].second });

	while (1) {
		queue<pair<int, int>> next_q;
		queue<pair<int, int>> next_s;
		while (!swan.empty()) {
			int sy = swan.front().first; int sx = swan.front().second;
			visited[sy][sx] = 1;
			swan.pop();

			for (int d = 0; d < 4; d++) {
				int nsy = sy + dy[d];
				int nsx = sx + dx[d];
				if (nsy == v[1].first and nsx == v[1].second) {
					ok = true; break;
				}

				if (nsy >= 1 and nsy <= R and nsx >= 1 and nsx <= C and !visited_s[nsy][nsx]) {
					if (graph[nsy][nsx] != 'X') swan.push({ nsy,nsx });
					else next_s.push({ nsy,nsx });
					visited_s[nsy][nsx] = visited_s[sy][sx] + 1;
				}
			}
		}
		swan = next_s;

		if (ok) break;
		else ret++;

		while (!q.empty()) {
			y = q.front().first; x = q.front().second;
			visited[y][x] = 1;
			q.pop();

			for (int d = 0; d < 4; d++) {
				ny = y + dy[d];
				nx = x + dx[d];

				if (ny >= 1 and ny <= R and nx >= 1 and nx <= C and !visited[ny][nx]) {
					visited[ny][nx] = visited[y][x] + 1;
					if (graph[ny][nx] != 'X') {
						q.push({ ny,nx });
					}
					else {
						next_q.push({ ny,nx });
						graph[ny][nx] = '.';
					}
				}
			}
		}
		q = next_q;
	}
	cout << ret;
	return 0;
}