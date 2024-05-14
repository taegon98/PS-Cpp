#include <iostream>
using namespace std;
#define INF 987654321
typedef long long ll;
ll N;
ll dp[1000001];

ll go(ll n) {
	if (n == 1) {
		return 1;
	}

	if (dp[n] != INF) {
		return dp[n] + 1;
	}

	if (n % 3 == 0) dp[n] = min(dp[n], go(n / 3));
	if (n % 2 == 0) dp[n] = min(dp[n], go(n / 2));
	dp[n] = min(dp[n], go(n - 1));

	return dp[n] + 1;
}
int main() {
	cin >> N;
	if (N == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i <= 1000000; i++) dp[i] = INF;
	go(N);

	cout << dp[N];
}