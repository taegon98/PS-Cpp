#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;
int N, from, to, visited[51];
vector<int> v[51];
vector<pair<int, int>> ret;

void check(int n) {
	int temp = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] != INF) {
			temp = max(temp, visited[i]);
		}
	}
	ret.push_back({ temp, n });
}

void go(int n) {
	for (auto var : v[n]) {
		if (visited[var] > visited[n] + 1) {
			visited[var] = visited[n] + 1;
			go(var);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cnt = 1;
	cin >> N;

	while (cin >> from >> to) {
		if (from == -1 and to == -1) break;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		fill(visited, visited + 51, INF);
		visited[i] = 0;
		go(i);
		check(i);
	}
	sort(ret.begin(), ret.end());

	for (int i = 1; i < ret.size(); i++) {
		if (ret[0].first == ret[i].first) cnt++;
	}
	cout << ret[0].first << " " << cnt << "\n";

	for (int i = 0; i < cnt; i++) {
		cout << ret[i].second << " ";
	}
}