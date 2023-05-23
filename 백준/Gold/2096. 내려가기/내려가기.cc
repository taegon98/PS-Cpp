#include <iostream>
using namespace std;
int N, a, b, c, dp[2][3], cur[2][3];

void update() {
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 3; j++) dp[i][j] = cur[i][j];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> a >> b >> c;
	dp[0][0] = dp[1][0] = a;
	dp[0][1] = dp[1][1] = b;
	dp[0][2] = dp[1][2] = c;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		cur[0][0] = max(dp[0][0] + a, dp[0][1] + a);
		cur[0][1] = max(max(dp[0][0] + b, dp[0][1] + b), dp[0][2] + b);
		cur[0][2] = max(dp[0][1] + c, dp[0][2] + c);

		cur[1][0] = min(dp[1][0] + a, dp[1][1] + a);
		cur[1][1] = min(min(dp[1][0] + b, dp[1][1] + b), dp[1][2] + b);
		cur[1][2] = min(dp[1][1] + c, dp[1][2] + c);
		update();
	}
	cout << max(max(dp[0][0], dp[0][1]), dp[0][2]) << " " << min(min(dp[1][0], dp[1][1]), dp[1][2]);
}