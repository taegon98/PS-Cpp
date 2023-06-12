#include <iostream>
using namespace std;
int N, M, tot, max_val = -987654321, arr[10001];
int l, h, m, ret = -987654321;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		max_val = max(max_val, arr[i]);
		tot += arr[i];
	}
	cin >> M;
	h = M;
	if (tot <= M) cout << max_val;
	else {
		while (l <= h) {
			m = (l + h) / 2;
			int temp = 0;
			for (int i = 0; i < N; i++) {
				if (arr[i] <= m) temp += arr[i];
				else temp += m;
			}
			if (M >= temp) {
				ret = max(ret, m);
				l = m + 1;
			}
			else h = m - 1;
		}
		cout << ret;
	}
}