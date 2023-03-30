#include <iostream>
#include <string.h>
using namespace std;
int N, M, tmp, ret1, ret2 = -987654321, ret3 = -987654321, num = 1;
int visited[54][54], coloring[2504], graph[54][54];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

int dfs(int y, int x, int depth) {
	visited[y][x] = num;

	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (!(graph[y][x] & (1 << d)) and !visited[ny][nx]) depth += dfs(ny, nx, 1);
	}
	return depth;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				coloring[num] = dfs(i, j, 1);
				ret2 = max(coloring[num++], ret2);
				ret1++;
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (j < N and visited[i][j] != visited[i][j + 1])
				ret3 = max(ret3, coloring[visited[i][j]] + coloring[visited[i][j + 1]]);
			if (i < M and visited[i][j] != visited[i + 1][j])
				ret3 = max(ret3, coloring[visited[i][j]] + coloring[visited[i + 1][j]]);
		}
	}
	cout << ret1 << "\n";
	cout << ret2 << "\n";
	cout << ret3 << "\n";
}