#include <iostream>
using namespace std;
typedef long long ll;
ll X, Y, Z, tmp_z, ret = 10987654321;
int main() {
	ll low = 0, mid, high = 1000000000;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
	cin >> X >> Y;
	Z = (Y * 100 / X);
	while (low <= high) {
		mid = (low + high) / 2;
		tmp_z = (Y + mid) * 100 / (X + mid);

		if (tmp_z == Z) low = mid + 1;
		else if (tmp_z != Z) {
			ret = ret < mid ? ret : mid;
			high = mid - 1;
		}
	}
	if (ret == 10987654321) cout << -1;
	else cout << ret;
}