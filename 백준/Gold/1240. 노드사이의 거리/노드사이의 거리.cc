#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, s, e, w, arr[1001][1001], visited[1001];
vector<int> v[1001];

int go(int cur, int e) {
	
	int temp = 0;

	if (!v[cur].size()) return 0;

	for (auto var : v[cur]) {
		if (var == e) {
			return arr[cur][var];
		}
		if (!visited[var]) {
			visited[cur] = 1;
			temp = go(var, e);
			if (temp) return temp += arr[cur][var];
		}
	}
	return temp;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N - 1; i++) {
		cin >> s >> e >> w;
		arr[s][e] = w;
		arr[e][s] = w;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	for (int i = 0; i < M; i++) {
		fill(visited, visited + 1001, 0);
		cin >> s >> e;
		cout << go(s, e) << "\n";
	}
}