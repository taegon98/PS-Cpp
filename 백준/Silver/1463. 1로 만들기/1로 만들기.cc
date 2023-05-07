#include <iostream>
using namespace std;
int N, dp[1000004], ret = 987654321;

int go(int n) {
	if (n == 1) return 0;
	if (dp[n] != 987654321) return dp[n];

	if (n % 3 == 0) dp[n] = min(dp[n], go(n / 3) + 1);
	if (n % 2 == 0) dp[n] = min(dp[n], go(n / 2) + 1);
	if (n - 1 >= 1) dp[n] = min(dp[n], go(n - 1) + 1);
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 1000004; i++) dp[i] = 987654321;
	cin >> N;
	cout << go(N) << "\n";
}