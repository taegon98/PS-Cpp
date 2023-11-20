#include <iostream>
#include <algorithm>
using namespace std;
int L, arr[51], n, l = 1, r, ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> L;

	for (int i = 0; i < L; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + L);
	cin >> n;

	for (int i = 0; i < L; i++) {
		if (arr[i] == n) {
			cout << 0;
			exit(0);
		}
		if (arr[i] > n) {
			if (i > 0)
				l = arr[i - 1] + 1;
			r = arr[i] - 1;
			break;
		}
	}
	ret = (n - l) * (r - n + 1) + (r - n);
	cout << ret;
}