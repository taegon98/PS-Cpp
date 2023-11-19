#include <iostream>
#include <queue>
using namespace std;
int M, N, arr[1001][1001], visited[1001][1001];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

bool go(int c) {
	queue<pair<int, int>> q;
	q.push({ 0, c });
	visited[0][c] = 1;

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (y == M - 1) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 or nx < 0 or ny >= M or nx >= N) continue;
			if (visited[ny][nx] or arr[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	cin >> M >> N;
	
	for (int i = 0; i < M; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] =  s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		if (!arr[0][i]) {
			if (go(i)) {
				cout << "YES";
				exit(0);
			}
		}
	}
	cout << "NO";
}