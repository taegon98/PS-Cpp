#include <iostream>
using namespace std;
#define INF 987654321
int N, arr[20][20], dp[1 << 20][20];

int go(int idx, int cur, int num) {
	if (idx == N) {
		if (arr[cur][1]) return arr[cur][1];
		else return INF;
	}
	if (dp[num][cur]) return dp[num][cur];
	dp[num][cur] = INF;
	
	for (int i = 0; i < N; i++) {
		if (num & (1 << i)) continue;
		if (arr[cur][i + 1] == 0) continue;
		dp[num][cur] = min(
			dp[num][cur], go(idx + 1, i + 1, num | (1 << i)) + arr[cur][i + 1]);
	}
	return dp[num][cur];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
	cout << go(1, 1, 1);
}