#include <iostream>
using namespace std;
#define INF 987654321
int N, ret = INF, dp[1004][3], arr[1004][3];

int go(int idx, int color) {
	if (idx > N) return 0;

	if (dp[idx][color]) return dp[idx][color];
	else dp[idx][color] = INF;

	if (color != 0) dp[idx][color] = min(dp[idx][color], go(idx + 1, 0) + arr[idx][0]);
	if (color != 1) dp[idx][color] = min(dp[idx][color], go(idx + 1, 1) + arr[idx][1]);
	if (color != 2) dp[idx][color] = min(dp[idx][color], go(idx + 1, 2) + arr[idx][2]);
	return dp[idx][color];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	for (int i = 0; i < 3; i++) ret = min(ret, go(1, i));
	cout << ret;
}