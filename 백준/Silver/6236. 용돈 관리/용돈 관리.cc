#include <iostream>
using namespace std;
int N, M, tot, rem, tmp_tot, low = -987654321, high, mid, ret;
int arr[100004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		low = max(low, arr[i]);
		tot += arr[i];
	}
	high = tot;
	while (low <= high) {
		tmp_tot = 1;
		mid = (low + high) / 2;
		rem = mid;
		for (int i = 0; i < N; i++) {
			if (rem - arr[i] < 0) {
				tmp_tot++;
				rem = mid;
			}
			rem -= arr[i];
		}
		if (tmp_tot <= M) {
			ret = mid;
			high = mid - 1;
		}
		else if (tmp_tot > M) low = mid + 1;
	}
	cout << ret;
}