#include <iostream>
#include <vector>
using namespace std;
int N, target, len, ret = -987654321;
int dp[1000004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> target;
		auto a = lower_bound(dp, dp + len, target);
		if (*a == 0) len++;
		*a = target;
	}
	cout << len;
}