#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N, ret = 987654321, arr[21][21], visited[21];

int cal(vector<int> v) {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			cnt += arr[v[i]][v[j]] + arr[v[j]][v[i]];
		}
	}
	return cnt;
}

int check() {
	vector<int> v1, v2;

	for (int i = 1; i <= N; i++) {
		if (visited[i]) v2.push_back(i);
		else v1.push_back(i);
	}

	return abs(cal(v1) - cal(v2));
}

void go(int idx, int cur_depth, int depth) {
	if (cur_depth == depth) {
		ret = min(ret, check());
		return;
	}

	for (int i = idx; i <= N; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		go(i, cur_depth + 1, depth);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < N - 1; i++) {
		fill(visited, visited + 21, 0);
		go(1, 0, i);
	}
	cout << ret;
}