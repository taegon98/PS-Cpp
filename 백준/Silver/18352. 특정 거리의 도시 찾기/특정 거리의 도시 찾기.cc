#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
bool ok = false;
int N, M, K, X, from, to, visited[300001];
vector<int> v[300001];

void go(int start, int depth) {
	if (depth > K) return;
	for (auto var : v[start]) {
		if (visited[var] <= depth) continue;
		else {
			visited[var] = depth;
			go(var, depth + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		v[from].push_back(to);
	}
	fill(visited, visited + N + 1, INF);
	visited[X] = 0;
	go(X, 1);
	for (int i = 1; i <= N; i++) {
		if (visited[i] == K) {
			cout << i << "\n";
			ok = true;
		}
	}
	if (!ok) cout << -1;
}