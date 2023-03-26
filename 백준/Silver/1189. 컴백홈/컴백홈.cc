#include <iostream>
using namespace std;

int R, C, K, ret;
char graph[6][6];
int visited[6][6];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x, int depth) {
	if (y == 1 and x == C) {
		if (depth == K) ret++;
		return;
	}
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny <1 or ny >R or nx <1 or nx > C or visited[ny][nx] or graph[ny][nx] == 'T') continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, depth + 1);
		visited[ny][nx] = 0;
	}
}

int main() {
	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)cin >> graph[i][j];
	}
	visited[R][1] = 1;
	dfs(R, 1, 1);
	cout << ret;
}