#include <iostream>
using namespace std;
int N, arr1[24], arr2[24], dp[104], ret = -987654321;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr1[i];
	for (int i = 1; i <= N; i++) cin >> arr2[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 99; j >= arr1[i]; j--) {
			int idx = j - arr1[i];
			int tmp = dp[idx] + arr2[i];
			dp[j] = max(tmp, dp[j]);
		}
		ret = max(ret, dp[99]);
	}
	if (ret == -987654321) cout << -1;
	else cout << ret;
}