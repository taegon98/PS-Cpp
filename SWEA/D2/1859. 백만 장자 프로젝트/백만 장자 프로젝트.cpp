#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef long long ll;

int main() {
	int T;

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		ll N, M, ret = 0;
		cin >> N;
		vector<ll> v;
		stack<ll> s;

		for (int i = 0; i < N; i++) {
			cin >> M;
			v.push_back(M);
		}

		s.push(v[v.size() - 1]);

		for (int i = N - 2; i >= 0; i--) {
			while (s.size() and s.top() > v[i]) {
				ret += (s.top() - v[i]);
				i--;
				if (i < 0) break;
			}
			if (i > 0)
				s.push(v[i]);
		}

		cout << "#" << tc << " " << ret << "\n";
	}
}