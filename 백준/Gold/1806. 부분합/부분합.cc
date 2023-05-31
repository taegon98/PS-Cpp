#include <iostream>
using namespace std;
typedef long long ll;
ll N, S, arr[100001], psum[100001];
ll l, r = 1, ret = 0xffffffff;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	while (l < r) {
		if (r > N) break;
		if (psum[r] - psum[l] >= S) {
			ret = min(ret, r - l);
			l++;
		}
		else if (psum[r] - psum[l] < S) r++;
	}
	if (ret == 0xffffffff) cout << 0;
	else cout << ret;
}