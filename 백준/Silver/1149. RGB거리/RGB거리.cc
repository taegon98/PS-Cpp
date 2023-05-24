#include <iostream>
using namespace std;
#define INF 987654321
int N, ret = INF, dp[2][3];

void update() { for (int i = 0; i < 3; i++) dp[0][i] = dp[1][i]; }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	for (int i = 1; i < N; i++) {
		cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
		dp[1][0] += min(dp[0][1], dp[0][2]);
		dp[1][1] += min(dp[0][0], dp[0][2]);
		dp[1][2] += min(dp[0][0], dp[0][1]);
		update();
	}
	cout << min(min(dp[0][0], dp[0][1]), dp[0][2]);
}