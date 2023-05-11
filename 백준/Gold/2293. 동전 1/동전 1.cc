#include <iostream>
using namespace std;
int n, k, coin[104], dp[10004] = { 1,0 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> coin[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j >= coin[i]) dp[j] = dp[j - coin[i]] + dp[j]; 
		}
	}
	cout << dp[k];
}