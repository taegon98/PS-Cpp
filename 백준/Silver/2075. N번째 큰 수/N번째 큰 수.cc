#include <iostream>
#include <stack>
using namespace std;
int N, temp;
stack<int> _s[1501];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			_s[j].push(temp);
		}
	}

	for (int i = 1; i <= N; i++) {
		int max_val = -987654321, idx;

		for (int j = 1; j <= N; j++) {
			if (_s[j].top() > max_val) {
				max_val = _s[j].top();
				idx = j;
			}
		}
		if (i == N) cout << _s[idx].top();
		_s[idx].pop();
	}
}