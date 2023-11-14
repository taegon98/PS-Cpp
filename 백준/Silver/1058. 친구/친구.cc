#include <iostream>
#include <vector>
using namespace std;
int N, ret;
string s;
vector<int> v[51];

void go(int depth, int idx, int visited[51]) {

	if (depth >= 2) return;

	for (auto var : v[idx]) {
		if (visited[var] == 1) continue;
		visited[var] = depth + 1;
		go(depth + 1, var, visited);
	}
}

int check(int visited[]) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i]) cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'N') continue;
			v[i].push_back(j + 1);
			v[j + 1].push_back(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		int visited[51] = { 0 };
		visited[i] = 1;
		go(0, i, visited);
		ret = max(ret, check(visited));
	}
	cout << ret - 1;
}