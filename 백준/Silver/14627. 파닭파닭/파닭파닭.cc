#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll S, C, L, tmp, low = 1, high = 1000000004, mid, ret = 0, tot;
vector<ll> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> S >> C;
	for (int i = 0; i < S; i++) {
		cin >> tmp;
		v.push_back(tmp);
		tot += tmp;
	}
	while (low <= high) {
		mid = (low + high) / 2;
		ll cnt = 0;
		for (ll num : v) {
			cnt += (num / mid);
		}
		if (cnt < C) high = mid - 1;
		else if (cnt >= C) {
			low = mid + 1;
			ret = ret < mid ? mid : ret;
		}
	}
	if (!ret) cout << tot;
	else {
		tot -= (C * ret);
		cout << tot;
	}
}