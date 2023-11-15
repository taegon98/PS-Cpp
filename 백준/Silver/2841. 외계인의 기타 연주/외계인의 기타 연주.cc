#include <iostream>
#include <stack>
using namespace std;
int N, P, str, plat, ret;
stack<int> _s[7];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> P;

	for (int i = 0; i < N; i++) {
		cin >> str >> plat;


		if (!_s[str].size() or _s[str].top() < plat) {
			_s[str].push(plat);
		}
		else {
			while (_s[str].size() and _s[str].top() > plat) {
				_s[str].pop();
				ret++;
			}
			if (!_s[str].size() or _s[str].top() != plat)
				_s[str].push(plat);
			else continue;
		}
		ret++;
	}
	cout << ret;
}