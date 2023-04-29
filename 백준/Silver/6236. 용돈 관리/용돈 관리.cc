#include <iostream>
using namespace std;
int N, M, tot, rem, tmp_tot, low, high, mid, ret;
int arr[100004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		tot += arr[i];
	}
	high = tot;

	while (low <= high) {
		bool flag = false;
		tmp_tot = 1;
		mid = (low + high) / 2;
		rem = mid;

		for (int i = 0; i < N; i++) {
			if (rem - arr[i] < 0) {
				tmp_tot++;
				rem = mid;
			}
			rem -= arr[i];
			if (rem < 0) {
				flag = true;
				break;
			}
		}
		if (flag) low = mid + 1;
		else {
			if (tmp_tot <= M) {
				ret = mid;
				high = mid - 1;
			}
			else if (tmp_tot > M) low = mid + 1;
		}
	}
	cout << ret;
}