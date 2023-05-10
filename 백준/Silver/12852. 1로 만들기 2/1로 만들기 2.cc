#include <iostream>
using namespace std;
int N, dp[1000004], arr[1000004], ret;

int go(int n) {
	if (n == 1) return 0;
	if (dp[n] != 987654321) return dp[n];

	if (n % 3 == 0) {
		int tmp = go(n / 3) + 1;
		if (dp[n] >= tmp) {
			dp[n] = tmp;
			arr[n] = n / 3;
		}
	}
	if (n % 2 == 0) {
		int tmp = go(n / 2) + 1;
		if (dp[n] >= tmp) {
			dp[n] = tmp;
			arr[n] = n / 2;
		}
	}
	if (n - 1 >= 1) {
		int tmp = go(n - 1) + 1;
		if (dp[n] >= tmp) {
			dp[n] = tmp;
			arr[n] = n - 1;
		}
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 1000004; i++) dp[i] = 987654321;
	cin >> N;
	ret = go(N);
	cout << ret << "\n";
	cout << N << " ";
	while (1) {
		if (arr[N] == 0) break;
		cout << arr[N] << " ";
		N = arr[N];
	}
}