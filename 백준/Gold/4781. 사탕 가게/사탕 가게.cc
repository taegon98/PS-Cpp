#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
int n, m1, m2, p1, p2, c, dp[10004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);
	while (1) {
		int ret = -987654321;
		memset(dp, 0, sizeof(dp));
		scanf("%d %d.%d", &n, &m1, &m2);
		if (n == 0) break;
		int M = m1 * 100 + m2;
		
		for (int i = 0; i < n; i++) {
			scanf("%d %d.%d", &c, &p1, &p2);
			int P = p1 * 100 + p2;
			for (int j = P; j <= M; ++j) {
				int add = dp[j - P] + c;
				dp[j] = max(dp[j], add);
			}
			ret = max(ret, dp[M]);
		}
		printf("%d\n", ret);
	}
}