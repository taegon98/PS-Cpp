#include <iostream>
#include <vector>
using namespace std;
int N, K, W, V, idx, ret = -987654321;
int dp[104][100004];
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> W >> V; v.push_back({ W,V });
	}
	for (auto a : v) {
		idx++;
		for (int i = 1; i <= K; i++) {
			if (i < a.first) dp[idx][i] = dp[idx - 1][i];
			else if (i >= a.first) {
				int insert = dp[idx - 1][i - a.first] + a.second;
				dp[idx][i] = max(dp[idx - 1][i], insert);
			}
		}
		ret = max(ret, dp[idx][K]);
	}
	cout << ret;
}