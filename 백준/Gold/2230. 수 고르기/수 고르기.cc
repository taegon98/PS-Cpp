#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll N, M, arr[100001], ret = 10987654321;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int l = 0, r = 1;

	while (r < N) {
		ll temp = arr[r] - arr[l];
		if (temp >= M) {
			ret = min(ret, temp);
			l++;
		}
		else if (temp < M) {
			r++;
		}
	}
	cout << ret;
}