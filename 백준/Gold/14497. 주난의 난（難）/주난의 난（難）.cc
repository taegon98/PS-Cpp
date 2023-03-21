#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N, M, x_1, y_1, x_2, y_2, y, x, ny, nx, ret;
bool ok = false;
char graph[304][304];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int sy, int sx) {
	bool visited[304][304];
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q1;
	q1.push({ sy,sx });
	visited[sy][sx] = 1;

	while (1) {
		ret++;
		queue<pair<int, int>> q2;
		while (!q1.empty()) {
			y = q1.front().first; x = q1.front().second;
			q1.pop();

			for (int d = 0; d < 4; d++) {
				ny = y + dy[d];
				nx = x + dx[d];
				if (graph[ny][nx] == '#') {
					ok = true;
					return;
				}
				if (ny >= 1 and ny <= N and nx >= 1 and nx <= M and !visited[ny][nx]) {
					visited[ny][nx] = true;
					if (graph[ny][nx] == '1') {
						q2.push({ ny,nx });
						graph[ny][nx] = '0';
					}
					else if (graph[ny][nx] == '0') q1.push({ ny,nx });
				}
			}
		}
		q1 = q2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> x_1 >> y_1 >> x_2 >> y_2;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> graph[i][j];
	}
	bfs(x_1, y_1);
	cout << ret;
}