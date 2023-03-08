#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX 10

int N, M, ret;
int graph[MAX][MAX];
bool visited[MAX][MAX] = { false };

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void bfs(int r, int c) {
	visited[r][c] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dr[d];
			int nx = x + dc[d];

			if (ny >= 0 and ny < N and nx >= 0 and nx < M and !visited[ny][nx]) {
				if (graph[ny][nx] == 0) {
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
				}
			}
		}
	}
}

void wall(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (graph[i][j] == 2 and !visited[i][j]) bfs(i, j);

		int tmp = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (graph[i][j] == 0 and !visited[i][j]) tmp++;
				if (tmp > ret) ret = tmp;
		for (int k = 0; k < MAX; k++) memset(visited[k], false, sizeof(bool) * MAX);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				graph[i][j] = 1;
				wall(++cnt);
				cnt--;
				graph[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> graph[i][j];

	wall(0);
	cout << ret;
	return 0;
}