#include <iostream>
using namespace std;
#define INF 987654321
int N, dp[1004][3][3], arr[1004][3], start;

int go(int idx, int color) {
	if (idx == N) {
		if (start == color) return INF;
		else return arr[idx][color];
	}

	if (dp[idx][start][color]) return dp[idx][start][color];
	else dp[idx][start][color] = INF;

	if (color != 0)
		dp[idx][start][color] = min(
			dp[idx][start][color], go(idx + 1, 0) + arr[idx][color]);
	if (color != 1)
		dp[idx][start][color] = min(
			dp[idx][start][color], go(idx + 1, 1) + arr[idx][color]);
	if (color != 2)
		dp[idx][start][color] = min(
			dp[idx][start][color], go(idx + 1, 2) + arr[idx][color]);
	return dp[idx][start][color];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	start = 0; int ret1 = go(1, 0);
	start = 1; int ret2 = go(1, 1);
	start = 2; int ret3 = go(1, 2);
	cout << min(min(ret1, ret2), ret3);
}