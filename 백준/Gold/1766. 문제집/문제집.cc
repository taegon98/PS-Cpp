#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, p1, p2, degree[32001];
vector<int> v[32001], ret;
priority_queue<int, vector<int>, greater<int>> pq;

void sorting() {
	for (int i = 1; i <= N; i++)
		if (!degree[i]) pq.push(i);

	while (pq.size()) {
		int temp = pq.top(); pq.pop();
		ret.push_back(temp);

		for (auto var : v[temp]) {
			degree[var]--;
			if (!degree[var]) pq.push(var);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> p1 >> p2;
		degree[p2]++;
		v[p1].push_back(p2);
	}
	sorting();
	for (auto var : ret) cout << var << " ";
}