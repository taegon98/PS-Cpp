#include <iostream>
using namespace std;

int N, M, tmp;
int dp[20000004];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < 0) dp[-(tmp) + 10000000]++;
		else dp[tmp]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (tmp < 0) cout << dp[-(tmp) + 10000000] << " ";
		else cout << dp[tmp] << " ";
	}
}