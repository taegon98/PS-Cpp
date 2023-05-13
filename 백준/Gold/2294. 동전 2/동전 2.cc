#include <iostream>
using namespace std;
#define INF 987654321
int N, K, v, ret = INF;
int dp[10004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i < 10004; i++) dp[i] = INF;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> v;
		for (int j = v; j <= K; j++) {
			dp[j] = min(dp[j], dp[j - v] + 1);
		}
		ret = min(ret, dp[K]);
	}
	if (ret == INF) cout << -1;
	else cout << ret;
}