#include <iostream>
using namespace std;
typedef long long ll;
ll N, K, ret1, ret2;
struct element {
	ll m[2], w[2];
};
element e[104];
ll dp[104][100004];

ll go(ll min, ll won, ll idx) {
	if (min > K) return 0;
	if (idx == N - 1) {
		return won;
	}
	//if (dp[idx][min]) return dp[idx][min];

	return dp[idx][min] = max(
		go(min + e[idx + 1].m[1], won + e[idx + 1].w[1], idx + 1),
		go(min + e[idx + 1].m[0], won + e[idx + 1].w[0], idx + 1));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> e[i].m[0] >> e[i].w[0] >> e[i].m[1] >> e[i].w[1];
	}
	ret1 = go(e[0].m[0], e[0].w[0], 0);
	//for (int i = 0; i < 104; i++) {
	//	for (int j = 0; j < 100004; j++) dp[i][j] = 0;
	//}
	ret2 = go(e[0].m[1], e[0].w[1], 0);
	cout << max(ret1, ret2);
}