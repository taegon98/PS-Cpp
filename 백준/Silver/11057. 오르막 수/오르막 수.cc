#include <iostream>
using namespace std;
int N, dp[1001][1001], ret;

int go(int depth, int num) {
	if (dp[depth][num]) return dp[depth][num];
	if (depth == N) return 1;

	for (int i = num; i <= 9; i++) {
		dp[depth][num] += go(depth + 1, i) % 10007;
	}
	return dp[depth][num] % 10007;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	cout << go(0, 0) % 10007;
}