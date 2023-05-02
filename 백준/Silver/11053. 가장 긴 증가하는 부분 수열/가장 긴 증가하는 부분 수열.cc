#include <iostream>
using namespace std;
int N, LIS[1004], ans[1004], ret = -987654321;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> LIS[i];
	for (int i = 1; i <= N; i++) {
		int cnt = 1;
		for (int j = 1; j < i; j++) {
			if (LIS[j] < LIS[i]) cnt = max(ans[j] + 1, cnt);
		}
		ans[i] = cnt;
		ret = max(ret, ans[i]);
	}
	cout << ret;
}