#include <iostream>
#include <vector>
using namespace std;
int N, K, W, V, idx, ret = -987654321;
int dp[100004];
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> W >> V; v.push_back({ W,V });
	}
	for (auto a : v) {
		for (int i = K; i >= a.first; i--)
			dp[i] = max(dp[i], a.second + dp[i - a.first]);
		ret = max(dp[K], ret);
	}
	cout << ret;
}