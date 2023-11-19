#include <iostream>
using namespace std;
int N, K, pos, w;
int arr[1000001], psum[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> w >> pos;
		arr[pos] = w;
	}

	psum[0] = arr[0];
	for (int i = 1; i <= 1000000; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	int l = -1, r = min(K * 2, 1000000);
	int ret = psum[r];

	while (r <= 1000000) {
		r++;
		l++;
		ret = max(ret, psum[r] - psum[l]);
	}
	cout << ret;
}