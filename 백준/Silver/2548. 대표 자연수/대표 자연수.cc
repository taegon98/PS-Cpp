#include <iostream>
#include <cmath>
using namespace std;
int N, arr[20001], tot, avg;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		tot += arr[i];
	}
	avg = tot / N;

	int s = 0;
	for (int i = 0; i < N; i++) {
		s += abs(arr[i] - avg);
	}
	int l = avg - 1, r = avg + 1, l_tot = 0, r_tot = 0, ret = avg;

	while (1) {
		l_tot = 0;
		for (int i = 0; i < N; i++) {
			l_tot += abs(arr[i] - l);
		}
		if (l_tot > s) break;
		else {
			ret = l;
			s = l_tot;
			l--;
		}
	}

	while (1) {
		r_tot = 0;
		for (int i = 0; i < N; i++) {
			r_tot += abs(arr[i] - r);
		}
		if (r_tot >= s) break;
		else {
			ret = r;
			s = r_tot;
			r++;
		}
	}
	cout << ret;
}