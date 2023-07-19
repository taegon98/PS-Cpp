#include <iostream>
using namespace std;
int n, m, cnt, ret = 0, arr[501][501], visited[501][501];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

int go(int y, int x) {
	int depth = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 or nx < 0 or ny >= n or nx >= m 
			or visited[ny][nx] or !arr[ny][nx]) continue;
		visited[ny][nx] = 1;
		depth += go(ny, nx);
	}
	return depth;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] and arr[i][j]) {
				visited[i][j] = 1;
				cnt++;
				ret = max(ret, go(i, j));
			}
		}
	}
	cout << cnt << "\n" << ret;
}