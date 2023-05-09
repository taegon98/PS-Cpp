#include <iostream>
using namespace std;
int T, W, dp[1004][4][34], location[1004];
int go(int t, int n, int cnt) {
	if (cnt < 0 or t > T) return 0;
	if (dp[t][n][cnt]) return dp[t][n][cnt];

	if (n == 1) {
		dp[t][1][cnt] += max(go(t + 1, n, cnt), go(t + 1, n + 1, cnt - 1));
	}
	if (n == 2) {
		dp[t][2][cnt] += max(go(t + 1, n - 1, cnt - 1), go(t + 1, n, cnt));
	}
	if (location[t] == n) dp[t][n][cnt]++;
	return max(dp[t][1][cnt], dp[t][2][cnt]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T >> W;
	for (int i = 1; i <= T; i++) cin >> location[i];
	cout << max(go(1, 1, W), go(1, 2, W - 1));
}