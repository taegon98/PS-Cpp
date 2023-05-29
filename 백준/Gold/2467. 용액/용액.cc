#include <iostream>
using namespace std;
typedef long long ll;
ll N, arr[100004], ret;
int l, r, ret_l, ret_r;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
	cin >> N;
	l = ret_l = 1, r = ret_r = N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	ret = arr[l] + arr[r];
	if (N == 2) {
		cout << arr[ret_l] << " " << arr[ret_r];
		exit(0);
	}
	while (l < r) {
		ll tmp = arr[l] + arr[r];
		if (abs(tmp) < abs(ret)) {
			ret = tmp;
			ret_l = l; ret_r = r;
		}
		if (tmp < 0) l++;
		else if (tmp > 0) r--;
		else {
			ret_l = l; ret_r = r;
			break;
		}
	}
	cout << arr[ret_l] << " " << arr[ret_r];
}