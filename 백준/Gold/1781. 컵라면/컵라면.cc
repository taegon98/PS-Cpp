#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, D, R, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D >> R;
		v.push_back({ D,R });
	}
	sort(v.begin(), v.end());
	for (pair<int, int> value : v) {
		pq.push(value.second);
		if (pq.size() > value.first) pq.pop();
	}
	while (pq.size()) {
		ret += pq.top(); pq.pop();
	}
	cout << ret;
}