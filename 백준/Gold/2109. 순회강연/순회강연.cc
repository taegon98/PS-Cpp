#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, p, d, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back({ d,p });
	}
	sort(v.begin(), v.end());
	for (pair<int, int> p : v) {
		pq.push(p.second);
		if (pq.size() > p.first) pq.pop();
	}
	while (pq.size()) {
		ret += pq.top();
		pq.pop();
	}
	cout << ret;
}