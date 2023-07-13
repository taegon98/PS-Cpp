#include <iostream>
using namespace std;
int N, M, K, r, c, ret = -987654321, arr[101][101], visited[101][101];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

int go(int y, int x) {
	visited[y][x] = 1;
	int temp = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny <= 0 or nx <= 0 or ny > N or nx > M or visited[ny][nx] or !arr[ny][nx]) continue;
		temp += go(ny, nx);
	}
	return temp;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		arr[r][c] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j] and arr[i][j]) {
				ret = max(ret, go(i, j));
			}
		}
	}
	cout << ret;
}