#include <iostream>
#include <queue>
#include <map>
using namespace std;
int T, N;
struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.first > b.first;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
pair<int, int> p;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		map<pair<int, int>, int> mp;
		int ret = 1;
		pair<int, int> temp1, temp2;
		for (int i = 0; i < N; i++) {
			cin >> p.first >> p.second;
			mp[p] = p.second;
			pq.push(p);
		}
		temp1 = pq.top(); pq.pop();
		while (pq.size()) {
			temp2 = pq.top(); pq.pop();
			if (mp[temp2] < mp[temp1]) {
				ret++;
				temp1 = temp2;
			}
		}
		cout << ret << "\n";
	}
}