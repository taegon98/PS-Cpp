#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, ret = -987654321;
pair<int, int> temp;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp.first >> temp.second;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	pq.push(v[0].second);
	for (int i = 1; i < N; i++) {
		if (v[i].first < pq.top()) {
			while (1) {
				if (v[i].first <= pq.top()) break;
				else if (v[i].first > pq.top()) pq.pop();
			}
		}
		else pq.pop();
		pq.push(v[i].second);
		if (ret < int(pq.size())) ret = int(pq.size());
	}
	cout << ret;
}