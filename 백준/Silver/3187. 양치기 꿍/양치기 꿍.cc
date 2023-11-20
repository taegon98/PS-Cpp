#include <iostream>
#include <queue>
using namespace std;
int R, C, visited[251][251], ret_v, ret_k;
char arr[251][251];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void go(int r, int c) {
	int cnt_v = 0, cnt_k = 0;
	queue<pair<int, int>> q;
	q.push({ r,c });
	visited[r][c] = 1;

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (arr[y][x] == 'v') cnt_v++;
		else if (arr[y][x] == 'k') cnt_k++;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 or nx < 0 or ny >= R or nx >= C) continue;
			if (visited[ny][nx]) continue;
			if (arr[ny][nx] == '#') continue;

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}
	if (cnt_v >= cnt_k) ret_v += cnt_v;
	else ret_k += cnt_k;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j]) continue;
			if (arr[i][j] == '#') continue;
			go(i, j);
		}
	}
	cout << ret_k << " " << ret_v;
}