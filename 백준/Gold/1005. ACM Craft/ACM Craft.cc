#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int T, N, K, W, n1, n2, t[1001], degree[1001], ret[1001];
vector<int> v[1001];

void sorting(queue<int>& q) {
	for (int i = 1; i <= N; i++) {
		if (!degree[i]) {
			q.push(i);
			ret[i] = t[i];
		}
	}

	while (q.size()) {
		int num = q.front(); q.pop();
		for (auto var : v[num]) {
			degree[var]--;
			if (!degree[var]) q.push(var);
			ret[var] = max(ret[num] + t[var], ret[var]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		queue<int> q;
		for (int i = 0; i < 1001; i++)v[i].clear();
		memset(ret, 0, sizeof(ret));
		memset(degree, 0, sizeof(degree));
		memset(t, 0, sizeof(t));

		cin >> N >> K;
		for (int i = 1; i <= N; i++) cin >> t[i];
		for (int i = 1; i <= K; i++) {
			cin >> n1 >> n2;
			degree[n2]++;
			v[n1].push_back(n2);
		}
		cin >> W;
		sorting(q);
		cout << ret[W] << "\n";
	}
}