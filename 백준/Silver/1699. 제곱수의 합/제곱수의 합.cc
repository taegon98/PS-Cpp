#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 987654321
int N, arr[320], dp[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	fill(dp + 1, dp + N + 1, INF);
	for (int i = 1; i <= (int)sqrt(N); i++) arr[i] = i * i;
	dp[1] = 1; dp[2] = 2; dp[3] = 3;

	for (int i = 4; i <= N; i++) {
		for (int j = 1; j <= sqrt(i); j++) {
			dp[i] = min(dp[i - (j * j)] + 1, dp[i]);
		}
	}
	cout << dp[N];
}