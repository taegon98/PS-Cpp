#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, num, ret = -987654321;
vector<int> v;
int visited[10];

void go(int depth, vector<int>& v2) {
	if (depth == N) {
		int tot = 0;
		for (int i = 0; i < N - 1; i++) tot += abs(v2[i] - v2[i + 1]);
		ret = max(ret, tot);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		v2.push_back(v[i]);
		visited[i] = 1;
		go(depth + 1, v2);
		v2.pop_back();
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		v.push_back(num);
	}
	vector<int> v2;
	go(0, v2);
	cout << ret;
}