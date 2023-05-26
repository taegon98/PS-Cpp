#include <iostream>
using namespace std;
int n, arr[10004], dp[10004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]), dp[i - 1]);
	}
	cout << dp[n];
}