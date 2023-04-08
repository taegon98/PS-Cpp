#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
ll N, K, M, V, tmp, ret, idx = 0;
vector<pair<ll, ll>> v;
vector<ll> b;
priority_queue<ll, vector<ll>, less<ll>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> M >> V;
		v.push_back({ M,V });
	}
	for (int i = 0; i < K; i++) {
		cin >> tmp; b.push_back(tmp);
	}
	sort(v.begin(), v.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < b.size(); i++) {
		while (idx < v.size() and b[i] >= v[idx].first) {
			pq.push(v[idx].second); idx++;
		}
		if (pq.size()) {
			ret += pq.top(); pq.pop();
		}
	}
	cout << ret;
}