#include <iostream>
using namespace std;

int R, C, ret = -987654321;
char graph[24][24];
bool visited[24][24] = { false };
bool alpha[25] = { false };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int sy, int sx, int depth) {
	ret = max(ret, depth);
	for (int d = 0; d < 4; d++) {
		int y = sy + dy[d];
		int x = sx + dx[d];

		if (y >= 0 and y < R and x >= 0 and x < C and !visited[y][x]) {
			if (!alpha[graph[y][x] - 65]) {
				alpha[graph[y][x] - 65] = true;
				visited[y][x] = true;
				dfs(y, x, depth + 1);
				alpha[graph[y][x] - 65] = false;
				visited[y][x] = false;
			}
		}
	}
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> graph[i][j];
	}
	visited[0][0] = true;
	alpha[graph[0][0] - 65] = true;
	dfs(0, 0, 1);
	cout << ret;
	return 0;
}