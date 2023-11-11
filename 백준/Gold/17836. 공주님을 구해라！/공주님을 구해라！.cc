#include <iostream>
#include <queue>
using namespace std;
int N, M, T, arr[101][101], visited[101][101], ret, ret1, ret2 = 987654321;
bool check[101][101] = { false };
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void no_wall(int r, int c, int w) {
	queue<pair<int, int>> q2;
	int visited2[101][101] = { 0 };
	q2.push({ r,c });
	visited2[r][c] = 1;

	while (q2.size()) {
		int y = q2.front().first;
		int x = q2.front().second;
		q2.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
			if (visited2[ny][nx]) continue;

			visited2[ny][nx] = visited2[y][x] + 1;
			q2.push({ ny,nx });
		}
	}
	ret2 = w + visited2[N - 1][M - 1] - 1;
}

void go() {
	bool flag = false;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
			if (arr[ny][nx] == 1) continue;
			if (visited[ny][nx]) continue;

			if (arr[ny][nx] == 2) {
				no_wall(ny, nx, visited[y][x]);
				flag = true;
			}

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	ret1 = visited[N - 1][M - 1] - 1;
	if (ret1 == -1) ret1 = 987654321;

	ret = min(ret1, ret2);
	if (ret == -1) {
		cout << "Fail";
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	go();
	if (ret <= T) cout << ret;
	else cout << "Fail";
}