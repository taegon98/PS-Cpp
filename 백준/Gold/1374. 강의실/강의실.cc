#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, temp, s, e, ret = 1;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp >> s >> e;
		v.push_back({ s, e });
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