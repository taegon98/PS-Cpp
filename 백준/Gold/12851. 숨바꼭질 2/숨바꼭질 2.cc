#include <iostream>
#include <queue>
using namespace std;

int N, K, x, nx, ret;
int visited[100004];
int cnt[100004];

void bfs(int pos) {
	queue<int> q;
	q.push(pos);
	visited[pos] = 1;
	cnt[pos] = 1;

	while (!q.empty()) {
		x = q.front(); q.pop();
		if (x == K) ret++;
		
		for (int i = 0; i < 3; i++) {
			if (i == 0) nx = x - 1;
			if (i == 1) nx = x + 1;
			if (i == 2) nx = x * 2;

			if (nx < 0 or nx > 100000) continue;
			if (!visited[nx]) {
				cnt[nx]++;
				q.push(nx);
				visited[nx] = visited[x] + 1;
			}
			else if (visited[nx] >= visited[x] + 1) {
				cnt[nx]++;
				q.push(nx);
			}
		}
	}
}

int main() {
	cin >> N >> K;
	bfs(N);
	cout << visited[K] - 1 << "\n" << ret;
	return 0;
}