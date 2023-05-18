#include <iostream>
#include <cstring>
using namespace std;
int N, M, from, to, arr[2004], dp[2004][2004];

bool check(int f, int t) {
	if (f >= t) return true;
	if (dp[f][t] != -1) return dp[f][t];

	while (f < t) {
		if (check(f + 1, t - 1) and arr[f] == arr[t]) {
			dp[f][t] = 1;
			return true;
		}
		else {
			dp[f][t] = 0;
			return false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> from >> to;
		if (check(from, to)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}