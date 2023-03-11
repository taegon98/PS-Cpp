#include <iostream>
#include <queue>
using namespace std;
#define MAX 104

int r, c, ret, curr_c, prev_c;
int graph[MAX][MAX];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

bool check() {
	curr_c = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) if (graph[i][j] == 1) curr_c++;
	}
	return curr_c;
}

void bfs(int row, int col) {
	bool visited[MAX][MAX] = { false };
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dr[d];
			int nx = x + dc[d];
			if (ny >= 0 and ny < r and nx >= 0 and nx < c and !visited[ny][nx]) {
				if (graph[ny][nx] == 1) graph[ny][nx] = 0;
				else if (graph[ny][nx] == 0) q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> graph[i][j];
		}
	}
	while (check() != 0) {
		prev_c = curr_c;
		bfs(0, 0);
		ret++;
	}
	cout << ret << "\n" << prev_c;
	return 0;
}