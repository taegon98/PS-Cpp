#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M, arr[51][51], visited[51][51], ret;
int dy[] = { -1,-1,0,1,1,1,0,-1 }, dx[] = { 0,1,1,1,0,-1,-1,-1 };

int go(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visited[r][c] = 1;

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (arr[ny][nx]) return visited[y][x];
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j]) continue;
			memset(visited, 0, sizeof(visited));
			ret = max(ret, go(i,j));
		}
	}
	cout << ret;
}