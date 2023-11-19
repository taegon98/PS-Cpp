#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
ll N, num, ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	stack<ll> _s;

	for (int i = 0; i < N; i++) {
		cin >> num;

		while (_s.size() and _s.top() <= num) {
			_s.pop();
		}
		ret += _s.size();
		_s.push(num);
	}
	cout << ret;
}