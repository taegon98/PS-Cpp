#include <iostream>
#include <deque>
using namespace std;
int N, K, arr[201][201], visited[201][201];
int s, r, c;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
deque<pair<int, int>> dq[1001];

void go() {
	for (int i = 1; i <= K; i++) {
		if (!dq[i].size()) continue;
		deque<pair<int, int>> temp;
		for (auto var : dq[i]) {
			visited[var.first][var.second] = 1;

			for (int j = 0; j < 4; j++) {
				int ny = var.first + dy[j];
				int nx = var.second + dx[j];

				if (ny <= 0 or nx <= 0 or ny > N or nx > N) continue;
				if (visited[ny][nx] or (arr[ny][nx] and i != arr[ny][nx])) continue;
				arr[ny][nx] = i;
				visited[ny][nx] = 1;
				temp.push_back({ ny,nx });
			}
		}
		dq[i] = temp;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			dq[arr[i][j]].push_back({ i,j });
		}
	}
	cin >> s >> r >> c;

	for (int i = 0; i < s; i++) go();
	cout << arr[r][c];
}