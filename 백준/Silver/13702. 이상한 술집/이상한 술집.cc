#include <iostream>
using namespace std;
typedef long long ll;
ll N, K, l = 1, r, m, ret, arr[10001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		r = max(r, arr[i]);
	}

	while (l <= r) {
		m = (l + r) / 2;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			cnt += (arr[i] / m);
		}

		if (cnt >= K) {
			ret = max(ret, m);
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	cout << ret;
}