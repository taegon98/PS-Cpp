#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, x, tmp;
int visited[100004];
int pre[100004];

void bfs(int pos) {
	queue<int> q;
	visited[pos] = 1;
	pre[pos] = -1;
	q.push(pos);

	while (!q.empty()) {
		x = q.front(); q.pop();
		if (x == K) return;
		for (int next : {x - 1, x + 1, x * 2}) {
			if (next >= 0 and next <= 100000 and !visited[next]) {
				q.push(next);
				visited[next] = visited[x] + 1;
				pre[next] = x;
			}
		}
	}
}

int main() {
	cin >> N >> K;
	vector<int> v;
	tmp = K;
	bfs(N);
	cout << visited[K] - 1 << "\n";
	while (1) {
		if (pre[tmp] == -1) {
			v.push_back(tmp);
			break;
		}
		v.push_back(tmp);
		tmp = pre[tmp];
	}
	reverse(v.begin(), v.end());
	for (int here : v) cout << here << " ";
	return 0;
}