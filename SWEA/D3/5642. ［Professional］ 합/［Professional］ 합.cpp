#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll T, N, arr[100001], psum[100001];

int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		ll ret = -987654321;
		fill(arr, arr + 100001, 0);
		fill(psum, psum + 100001, 0);

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= N; i++) {
			psum[i] = max(psum[i - 1] + arr[i], arr[i]);
			ret = max(ret, psum[i]);
		}
		cout << "#" << tc << " " << ret << "\n";
	}
}