#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, p1, p2, ans, ret = 987654321;
vector<int> v[101];

void go(int n) {
	int visited[101] = { 0 };
	int tot = 0;
	queue<int> q;
	q.push(n);
	visited[n] = 1;

	while (q.size()) {
		int temp = q.front(); q.pop();
		for (auto var : v[temp]) {
			if (visited[var]) continue;
			q.push(var);
			visited[var] = visited[temp] + 1;
		}
	}
	for (int i = 1; i <= N; i++) tot += (visited[i] - 1);
	if (tot < ret) {
		ret = tot;
		ans = n;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> p1 >> p2;
		v[p1].push_back(p2);
		v[p2].push_back(p1);
	}
	for (int i = 1; i <= N; i++) go(i);
	cout << ans;
}