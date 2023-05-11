#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int n, k, coin[104], dp[10004], ret = INF;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> coin[i];
	for (int i = 0; i < 10004; i++) dp[i] = INF;
	sort(coin + 1, coin + n + 1);
	for (int i = 1; i <= n; i++) {
		int q;
		for (int j = 0; j <= k; j++) {
			if (j % coin[i] == 0) {
				q = j / coin[i];
				dp[j] = min(dp[j], q);
			}
			else if (j >= coin[i]) {
				int tmp = INF;
				for (int k = 0; k <= q; k++) {
					int idx = j - coin[i] * k;
					tmp = min(tmp, dp[idx] + ((j - idx) / coin[i]));
				}
				dp[j] = min(dp[j], tmp);
			}
			ret = min(ret, dp[k]);
		}
	}
	if (ret == INF) cout << -1;
	else cout << ret;
}