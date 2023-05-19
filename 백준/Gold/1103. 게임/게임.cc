#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int N, M, ret = -987654321, arr[54][54], dp[54][54], visited[54][54];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
stack<pair<int, int>> _stack;
string s;

int dfs(int y, int x, int depth) {
	if (dp[y][x]) return dp[y][x];
	for (int d = 0; d < 4; d++) {
		int ny = y + dy[d] * arr[y][x];
		int nx = x + dx[d] * arr[y][x];
		if (ny < 0 or nx < 0 or ny >= N or nx >= M or
			arr[ny][nx] == -1) continue;
		if (visited[ny][nx]) {
			cout << -1;
			exit(0);
		}
		visited[ny][nx] = 1;
		dp[y][x] = max(dp[y][x], 1 + dfs(ny, nx, depth + 1));
		visited[ny][nx] = 0;
	}
	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'H') arr[i][j] = -1;
			else arr[i][j] = s[j] - '0';
		}
	}
	visited[0][0] = 1;
	cout << dfs(0, 0, 0) + 1;
}