#include <iostream>
#include <queue>
using namespace std;

int N, K, x, tmp, ret = -1, t = 1;
int visited[2][500004];

void bfs(int pos) {
	if (pos == K) {
		ret = 0;
		return;
	}
	queue<int> q;
	visited[0][pos] = 1;
	q.push(pos);

	while (!q.empty()) {
		tmp += t;
		if (tmp > 500000) return;
		int size = q.size();

		for (int here = 0; here < size; here++) {
			x = q.front(); q.pop();
			if (visited[t % 2][tmp]) {
				ret = t;
				return;
			}
			for (int next : {x - 1, x + 1, x * 2}) {
				if (next >= 0 and next <= 500000 and !visited[t % 2][next]) {
					q.push(next);
					visited[t % 2][next] = visited[(t + 1) % 2][x] + 1;
					if (next == tmp) {
						ret = t;
						return;
					}
				}
			}
		}
		t++;
	}
}

int main() {
	cin >> N >> K;
	tmp = K;
	bfs(N);
	if (ret != -1) cout << ret << "\n";
	else if (ret == -1) cout << -1 << "\n";
	return 0;
}