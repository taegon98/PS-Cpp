#include <iostream>
using namespace std;
typedef long long ll;
ll N, arr[104], dp[104][104];
ll go(int n, int idx) {
	if (n < 0 or n > 20) return 0;
	if (idx == N - 1) {
		if (n == arr[N - 1]) return 1;
		else return 0;
	}
	if (dp[n][idx]) return dp[n][idx];
	
	dp[n][idx] += go(n + arr[idx], idx + 1);//누적 값, 현재 인덱스(연산 되어야 하는)
	dp[n][idx] += go(n - arr[idx], idx + 1);
	return dp[n][idx];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cout << go(arr[0], 1);
}