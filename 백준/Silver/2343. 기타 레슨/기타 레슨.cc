#include <iostream>
using namespace std;
typedef long long ll;
ll N, M, tot, lecture[100004];
ll low = -987654321, high, mid, cnt, rem, ret = 987654321;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> lecture[i];
		low = max(low, lecture[i]);
		tot += lecture[i];
	}
	high = tot;

	while (low <= high) {
		mid = (low + high) / 2;
		cnt = 1;
		rem = mid;
		for (int i = 0; i < N; i++) {
			if (rem - lecture[i] < 0) {
				cnt++;
				rem = mid;
			}
			rem -= lecture[i];
		}
		if (cnt <= M) {
			ret = min(ret, mid);
			high = mid - 1;
		}
		else if (cnt > M) {
			low = mid + 1;
		}
	}
	cout << ret;
}