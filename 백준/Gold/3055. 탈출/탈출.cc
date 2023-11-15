#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int R, C, sy, sx, ey, ex, ret, visited[51][51];
vector<pair<int, int>> v;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
char arr[51][51];
int flood_arr[51][51];

void flood() {

	while (1) {
		vector<pair<int, int>> temp;

		for (auto var : v) {
			for (int i = 0; i < 4; i++) {
				int ny = var.first + dy[i];
				int nx = var.second + dx[i];

				if (ny < 0 or nx < 0 or ny >= R or nx >= C) continue;
				if (arr[ny][nx] == 'X' or arr[ny][nx] == 'D' or arr[ny][nx] == '*') continue;
				arr[ny][nx] = '*';
				flood_arr[ny][nx] = flood_arr[var.first][var.second] + 1;
				temp.push_back({ ny,nx });
			}
		}
		v = temp;
		if (!v.size()) return;
	}
}

void bfs(int r, int c) {

	queue<pair<int, int>> q;
	q.push({ r,c });
	visited[r][c] = 1;

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == ey and x == ex) {
			cout << visited[y][x] - 1;
			exit(0);
		}
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 or nx < 0 or ny >= R or nx >= C) continue;
			if (arr[ny][nx] == 'X' or visited[ny][nx]) continue;
			if (arr[ny][nx] == '*' and flood_arr[ny][nx] <= visited[y][x]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sy = i; sx = j;
			}
			else if (arr[i][j] == 'D') {
				ey = i; ex = j;
			}
			else if (arr[i][j] == '*') {
				v.push_back({ i,j });
			}
		}
	}
	flood();
	bfs(sy, sx);
	cout << "KAKTUS";
}