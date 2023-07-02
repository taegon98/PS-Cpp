#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m, Y, X, graph[1001][1001], visited[1001][1001];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void go(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r,c });

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 or nx < 0 or ny >= n or nx >= m or !graph[ny][nx] or visited[ny][nx] != -1) continue;
			q.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);
	memset(visited, -1, sizeof(visited));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 2) {
				Y = i; X = j;
			}
		}
	}
	visited[Y][X] = 0;
	go(Y, X);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0 or graph[i][j] == 2) cout << "0 ";
			else cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}