#include <iostream>
using namespace std;
int n, tmp, l, r, arr[100004], tot = 0, ret = -987654321;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		tot += arr[i];
		ret = max(ret, tot);
		if (tot < 0) tot = 0;
	}
	cout << ret;
}