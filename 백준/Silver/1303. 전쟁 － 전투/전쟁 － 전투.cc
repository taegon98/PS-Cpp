#include <iostream>
using namespace std;
int N, M, visited[101][101], ret1, ret2;
char arr[101][101];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

int go(int y, int x, char c) {
	int cnt = 1;
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 or nx < 0 or ny >= N or nx >= M or visited[ny][nx]) continue;
		if (c == 'W' and arr[ny][nx] == 'B') continue;
		if (c == 'B' and arr[ny][nx] == 'W') continue;	
		
		cnt += go(ny, nx, c);
	}
	return cnt;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			arr[i][j] = s[j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				int temp = go(i, j, arr[i][j]);
				if (arr[i][j] == 'W') ret1 += (temp * temp);
				else ret2 += (temp * temp);
			}
		}
	}

	cout << ret1 << " " << ret2;
}