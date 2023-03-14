#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

int N, L, R, u, tot, cnt, ret, x, y;
int graph[54][54];
bool visited[54][54] = { false };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>> v;

int bfs(int sy, int sx) {
	bool flag = false;
	tot = 0, cnt = 1;

	queue<pair<int, int>> q;
	q.push({ sy,sx });
	v.push_back({ sy,sx });
	visited[sy][sx] = true;
	tot += graph[sy][sx];

	while (!q.empty()) {
		y = q.front().first; x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny >= 0 and ny < N and nx >= 0 and nx < N and !visited[ny][nx]) {
				int diff = abs(graph[y][x] - graph[ny][nx]);
				if (diff >= L and diff <= R) {
					tot += graph[ny][nx]; cnt++;
					q.push({ ny,nx }); visited[ny][nx] = true;
					v.push_back({ ny,nx });
					flag = true;
				}
			}
		}
	}
	if (flag) return 1;
	else return 0;
}

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> graph[i][j];
	}

	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					int tmp = bfs(i, j);
					if (tmp) {
						u += tmp;
						for (pair<int, int> there : v) graph[there.first][there.second] = tot / cnt;
					}
					v.clear();
				}
			}
		}
		if (u) {
			ret++; u = 0;
			memset(visited, false, sizeof(visited));
		}
		else break;
	}
	cout << ret;
	return 0;
}