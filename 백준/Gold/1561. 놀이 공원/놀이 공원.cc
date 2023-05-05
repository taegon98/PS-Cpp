#include <iostream>
using namespace std;
typedef long long ll;
ll arr[10004], ret[10004], idx, tmp_mid;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll N, M, tmp;
	cin >> N >> M;
	if (N <= M) {
		cout << N;
		return 0;
	}
	else {
		for (int i = 0; i < M; i++) cin >> arr[i];
		ll low = 1, high = 9e15, mid;
		while (low <= high) {
			mid = (low + high) / 2;
			ll cnt = M;
			for (int j = 0; j < M; j++) cnt += (mid / arr[j]);
			if (cnt >= N) {
				tmp_mid = mid;
				high = mid - 1;
			}
			else if (cnt < N) low = mid + 1;
		}
		tmp = M;
		for (int j = 0; j < M; j++) {
			tmp += ((tmp_mid - 1) / arr[j]);
			ll rem = tmp_mid % arr[j];
			if (rem == 0) ret[j] = arr[j];
			else ret[j] = arr[j] - rem;
		}
		if (tmp == N) {
			cout << 1; return 0;
		}
		else {
			for (int j = 0; j < M; j++) {
				if (arr[j] == ret[j]) tmp++;
				if (tmp == N) {
					cout << j + 1;
					return 0;
				}
			}
		}
	}
}