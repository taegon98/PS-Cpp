#include <iostream>
#include <cstring>
using namespace std;
#define INF 987654321
int N, dp[1004][3], arr[1004][3], start, ret = INF;

int go(int idx, int color) {
	if (idx == N) {
		if (start == color) return INF;
		else return arr[idx][color];
	}

	if (dp[idx][color]) return dp[idx][color];
	else dp[idx][color] = INF;

	if (color != 0)
		dp[idx][color] = min(
			dp[idx][color], go(idx + 1, 0) + arr[idx][color]);
	if (color != 1)
		dp[idx][color] = min(
			dp[idx][color], go(idx + 1, 1) + arr[idx][color]);
	if (color != 2)
		dp[idx][color] = min(
			dp[idx][color], go(idx + 1, 2) + arr[idx][color]);
	return dp[idx][color];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	start = 0; ret = min(ret, go(1, 0));
	memset(dp, 0, sizeof(dp));
	start = 1; ret = min(ret, go(1, 1));
	memset(dp, 0, sizeof(dp));
	start = 2; ret = min(ret, go(1, 2));
	cout << ret;
}