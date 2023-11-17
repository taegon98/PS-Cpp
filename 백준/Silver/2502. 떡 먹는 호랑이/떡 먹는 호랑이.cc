#include <iostream>
using namespace std;
int D, K, arr1[31], arr2[31], diff, cur = 1;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> D >> K;
	arr1[1] = 1;
	arr1[2] = 1;
	arr2[1] = 1;
	arr2[2] = 2;

	for (int i = 3; i <= D; i++) {
		arr1[i] = arr1[i - 2] + arr1[i - 1];
		arr2[i] = arr2[i - 2] + arr2[i - 1];
	}
	diff = arr2[D] - arr1[D];

	while (1) {
		int arr[31] = { 0 };
		arr[1] = cur;
		arr[2] = cur;

		for (int i = 3; i <= D; i++) {
			arr[i] = arr[i - 2] + arr[i - 1];
		}

		int temp = (K - arr[D]) % diff;
		int num = (K - arr[D]) / diff;

		if (temp == 0) {
			cout << cur << "\n" << cur + num;
			exit(0);
		}
		cur++;
	}
}