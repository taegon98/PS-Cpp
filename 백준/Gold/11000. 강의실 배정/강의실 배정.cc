#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, s, t, ret = 1;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		v.push_back({ s,t });
	}
	sort(v.begin(), v.end());
	pq.push(v[0].second);

	for (int i = 1; i < N; i++) {
		while (pq.size() and pq.top() <= v[i].first) pq.pop();
		pq.push(v[i].second);
		ret = max(ret, (int)pq.size());
	}
	cout << ret;
}