#include <iostream>
using namespace std;
#define INF 987654321
int arr[100004], dp[100004][5][5], idx = 1;

int go(int curr, int l, int r) {
	if (curr == idx - 1) return 0;
	if (dp[curr][l][r] != INF) return dp[curr][l][r];

	if (l == 0 and arr[curr + 1] != r)
		dp[curr][l][r] = min(dp[curr][l][r], go(curr + 1, arr[curr + 1], r) + 2);
	else if (!abs(l - arr[curr + 1]) and arr[curr + 1] != r)
		dp[curr][l][r] = min(dp[curr][l][r], go(curr + 1, arr[curr + 1], r) + 1);
	else if (abs(l - arr[curr + 1]) == 2 and arr[curr + 1] != r)
		dp[curr][l][r] = min(dp[curr][l][r], go(curr + 1, arr[curr + 1], r) + 4);
	else 
		dp[curr][l][r] = min(dp[curr][l][r], go(curr + 1, arr[curr + 1], r) + 3);
	if (r == 0 and arr[curr + 1] != l)
		dp[curr][l][r] = min(dp[curr][l][r], go(curr + 1, l, arr[curr + 1]) + 2);
	else if (!abs(r - arr[curr + 1]) and arr[curr + 1] != l)
		dp[curr][l][r] = min(dp[curr][l][r], go(curr + 1, l, arr[curr + 1]) + 1);
	else if (abs(r - arr[curr + 1]) == 2 and arr[curr + 1] != l)
		dp[curr][l][r] = min(dp[curr][l][r], go(curr + 1, l, arr[curr + 1]) + 4);
	else
		dp[curr][l][r] = min(dp[curr][l][r], go(curr + 1, l, arr[curr + 1]) + 3);
	return dp[curr][l][r];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 100004; i++) {
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++) dp[i][j][k] = INF;
	}
	while (1) {
		cin >> arr[idx];
		if (!arr[idx]) break;
		else idx++;
	}
	cout << go(0, 0, 0);
}