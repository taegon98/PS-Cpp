#include <iostream>
using namespace std;
int N, dp[1000001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	dp[1] = 1;
	dp[2] = 2;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	}
	cout << dp[N];
}