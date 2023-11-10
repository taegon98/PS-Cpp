#include <iostream>
using namespace std;
typedef long long ll;
int T, N, arr[1000001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		ll tot = 0, cnt = 0, max_val = -987654321;

		for (int i = N - 1; i >= 0; i--) {
			if (max_val < arr[i]) max_val = arr[i];
			else {
				tot += (max_val - arr[i]);
			}
		}
		cout << tot << "\n";
	}
}