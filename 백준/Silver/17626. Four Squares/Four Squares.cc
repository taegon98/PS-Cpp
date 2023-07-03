#include <iostream>
#include <cmath>
#include <algorithm>
#define INF 987654321
using namespace std;
int n, dp[50001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fill(dp, dp + 50002, INF);
	dp[0] = 0, dp[1] = 1; dp[2] = 2; dp[3] = 3;
	cin >> n;
	for (int i = 4; i <= n; i++) {
		int temp = floor(sqrt(i));
		for (int j = 1; j <= temp; j++) {
			dp[i] = min(dp[i - j * j] + 1, dp[i]);
		}
	}
	cout << dp[n];
}