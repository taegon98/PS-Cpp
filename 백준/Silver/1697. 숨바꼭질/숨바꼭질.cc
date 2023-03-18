#include <iostream>
#include <queue>
using namespace std;

int N, K, x, nx;
int visited[100004];

void bfs() {
	queue<int> q;

	visited[N] = 1;
	q.push(N);

	while (!q.empty()) {
		x = q.front(); q.pop();

		if (x == K) return;
		for (int i = 0; i < 3; i++) {
			if (i == 0)nx = x + 1;
			if (i == 1)nx = x - 1;
			if (i == 2)nx = x * 2;

			if (nx >= 0 and nx <= 100000 and !visited[nx]) {
				visited[nx] = visited[x] + 1;
				q.push(nx);
			}
		}

	}
}

int main() {
	cin >> N >> K;
	bfs();
	cout << visited[K] - 1;
	return 0;
}