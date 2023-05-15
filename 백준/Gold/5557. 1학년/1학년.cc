#include <iostream>
using namespace std;
typedef long long ll;
ll N, arr[104], dp[104][104][104];
ll go(int n, int depth, int idx) {
	if (n < 0 or n > 20) return 0;
	if (depth == N - 1) {
		if (n == arr[N - 1]) return 1;
		else return 0;
	}
	if (dp[n][arr[idx]][depth]) return dp[n][arr[idx]][depth];
	if (dp[n][arr[idx]][depth]) return dp[n][arr[idx]][depth];

	dp[n][arr[idx]][depth] += go(n + arr[idx], depth + 1, idx + 1);
	dp[n][arr[idx]][depth] += go(n - arr[idx], depth + 1, idx + 1);
	return dp[n][arr[idx]][depth];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cout << go(arr[0], 1, 1);
}