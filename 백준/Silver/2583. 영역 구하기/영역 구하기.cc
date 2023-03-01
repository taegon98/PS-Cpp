#include <iostream>
#include <string.h>
#include <list>
#define MAX 104

using namespace std;

int M, N, K, ret, area;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int graph[MAX][MAX];
bool visited[MAX][MAX] = { false };
list<int> l;

void dfs(int y, int x) {
	visited[y][x] = true;

	for (int d = 0; d < 4; d++) {
		int ny = y + dr[d];
		int nx = x + dc[d];

		if (ny >= 0 and ny < M and nx >= 0 and nx < N) {
			if (!visited[ny][nx] and graph[ny][nx] == 0) {
				dfs(ny, nx); area++;
			}
		}
	}
	return;
}

int main() {
	int x1, y1, x2, y2;
	cin >> M >> N >> K;

	for (int tc = 0; tc < K; tc++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y2; i > y1; i--) {
			for (int j = x1; j < x2; j++) {
				graph[M - i][j] = 1;
			}
		}
	}

	for (int r = 0; r < M; r++) {
		for (int c = 0; c < N; c++) {
			if (!visited[r][c] and graph[r][c] == 0) {
				area = 1;
				dfs(r, c); ret++;
				l.push_back(area);
			}
		}
	}
	l.sort();

	cout << ret << "\n";
	while (!l.empty()) {
		cout << l.front() << " "; l.pop_front();
	}
	return 0;
}