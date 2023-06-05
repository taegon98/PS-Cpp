#include <iostream>
using namespace std;
typedef long long ll;
ll N, ret, dp[101][10];

ll go(ll num, ll depth) {
	if (num < 0 or num > 9) return 0;
	if (depth == N) return 1;

	if (dp[depth][num]) return dp[depth][num];

	dp[depth][num] += go(num + 1, depth + 1) % 1000000000;
	dp[depth][num] += go(num - 1, depth + 1) % 1000000000;
	return dp[depth][num] % 1000000000;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= 9; i++) ret += go(i, 1);
	cout << ret % 1000000000;
}