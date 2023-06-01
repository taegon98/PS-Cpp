#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, n1, n2, degree[32001];
vector<int> v[32001];
vector<int> ret;
queue<int> q;

void sorting() {
	for (int i = 1; i <= N; i++) {
		if (!degree[i]) q.push(i);
	}

	while (q.size()) {
		int temp = q.front(); q.pop();
		ret.push_back(temp);

		for (auto var : v[temp]) {
			degree[var]--;
			if (!degree[var]) q.push(var);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		degree[n2] += 1;
	}
	sorting();
	for (auto var : ret) cout << var << " ";
}