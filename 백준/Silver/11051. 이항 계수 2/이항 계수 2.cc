#include <iostream>
using namespace std;
int N, K, cnt;
int dp[1004][1004];

int bin(int n, int k) {
	cnt++;
	if (dp[n][k]) return dp[n][k];
	if (k == 0 or n == k) {
		dp[n][k] = 1;
		return dp[n][k];
	}
	else {
		dp[n][k] = (bin(n - 1, k) + bin(n - 1, k - 1)) % 10007;
	}
	return dp[n][k];
}

int main(void) {
	cin >> N >> K;
	cout << bin(N, K);
}