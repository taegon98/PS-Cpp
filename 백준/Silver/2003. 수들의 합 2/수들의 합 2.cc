#include <iostream>
using namespace std;
int N, M, arr[10001], psum[10001], ret;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int l = 0, r = 1;

	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 1; i <= N; i++) psum[i] = psum[i - 1] + arr[i];

	while (l <= r) {
		if (r > N) break;
		if (psum[r] - psum[l] <= M) {
			if (psum[r] - psum[l] == M) ret++;
			r++;
		}
		else if (psum[r] - psum[l] > M) l++;
	}
	cout << ret;
}