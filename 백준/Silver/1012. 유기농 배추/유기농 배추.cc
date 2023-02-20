#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string.h>
#define MAX 54
using namespace std;

int T, M, N, K, X, Y;
int graph[MAX][MAX];
bool visited[MAX][MAX] = { false };
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void dfs(int x, int y) {

	visited[x][y] = true;

	for (int d = 0; d < 4; d++) {
		int ny = x + dr[d];
		int nx = y + dc[d];

		if (nx >= 0 and nx < M and ny >= 0 and ny < N) {
			if (!visited[ny][nx] and graph[ny][nx] == 1)
				dfs(ny, nx);
		}
	}
}

int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int cnt = 0;
		cin >> M >> N >> K;
		
		for (int i = 0; i < MAX; i++) {
			memset(graph[i], 0, sizeof(int) * MAX);
			memset(visited[i], false, sizeof(bool) * MAX);
		}

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			graph[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visited[i][j] and graph[i][j] == 1) {
					dfs(i, j); cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}