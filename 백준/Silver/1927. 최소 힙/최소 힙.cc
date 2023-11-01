#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;
long long N, x;
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) {
			if (!pq.size()) v.push_back(0);
			else {
				v.push_back(pq.top());
				pq.pop();
			}
		}
		else pq.push(x);
	}

	for (auto var : v) cout << var << "\n";
}