#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, M, depth = 1;
int graph[101][101] = { 0 };
int weight[101][101]= { 0 };

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;

void dfs(int n, int m) {
	q.emplace(make_pair(n, m));
	weight[n][m] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dr[d];
			int ny = y + dc[d];

			if (nx >= 1 and nx <= N and ny >= 1 and ny <= M) {
				if (graph[nx][ny] == 1 and !weight[nx][ny]) {
					q.push(make_pair(nx, ny));
					weight[nx][ny] = weight[x][y] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	dfs(1, 1);
	cout << weight[N][M];

	return 0;
}