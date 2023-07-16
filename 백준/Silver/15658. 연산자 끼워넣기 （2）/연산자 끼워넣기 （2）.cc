#include <iostream>
using namespace std;
int N, arr[12], op[4], ret_max = -1000000001, ret_min = 1000000001;

void go(int num, int idx) {
	if (idx == N) {
		ret_max = max(ret_max, num);
		ret_min = min(ret_min, num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			op[i]--;
			if (i == 0) go(num + arr[idx], idx + 1);
			if (i == 1) go(num - arr[idx], idx + 1);
			if (i == 2) go(num * arr[idx], idx + 1);
			if (i == 3) go(num / arr[idx], idx + 1);
			op[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> op[i];
	go(arr[0], 1);
	cout << ret_max << "\n" << ret_min;
}