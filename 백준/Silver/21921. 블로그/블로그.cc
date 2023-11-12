#include <iostream>
using namespace std;
int N, X, arr[250001], psum[250001], ret = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> X;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	int l = 0, r = X;

	for (int i = 0; i <= N - X; i++) {
		ret = max(ret, psum[r] - psum[l]);
		r++; l++;
	}

	if (!ret) {
		cout << "SAD";
	}
	else {
		int cnt = 0;
		l = 0; r = X;
		for (int i = 0; i <= N - X; i++) {
			if (psum[r] - psum[l] == ret) cnt++;
			r++; l++;
		}
		cout << ret << "\n" << cnt;
	}
}