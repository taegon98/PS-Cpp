#include <iostream>
using namespace std;
int N, K, psum[1000001], temp, ret = 987654321;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> temp;
		if (temp == 1) {
			psum[i] = psum[i - 1] + 1;
		}
		else psum[i] = psum[i - 1];
	}
	
	int l = 0, r = 1;

	while (r <= N) {
		temp = psum[r] - psum[l];
		if (temp < K) r++;
		else {
			ret = min(ret, r - l);
			l++;
		}
	}
	if (ret == 987654321) cout << -1;
	else cout << ret;
}