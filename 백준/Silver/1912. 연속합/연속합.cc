#include <iostream>
using namespace std;
int n, tmp, l, r, arr[100004], sum[100004], ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sum[0] = arr[0];
	ret = sum[0];
	for (int i = 1; i < n; i++) {
		sum[i] = max(sum[i - 1] + arr[i], arr[i]);
		ret = max(ret, sum[i]);
	}
	cout << ret;
}