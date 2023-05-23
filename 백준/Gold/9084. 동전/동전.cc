#include <iostream>
using namespace std;
int T, N, coin[21], target;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int dp[10001] = { 1,0 };
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> coin[i];
		cin >> target;
		
		for (int i = 1; i <= N; i++) {
			for (int j = coin[i]; j <= target; j++) {
				dp[j] = dp[j - coin[i]] + dp[j];
			}
		}
		cout << dp[target] << "\n";
	}
}