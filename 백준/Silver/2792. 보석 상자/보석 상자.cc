#include <iostream>
#include <vector>
using namespace std;
int N, M, tmp, low = 1, mid, high = -987654321, ret;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> tmp;
		high = max(tmp, high);
		v.push_back(tmp);
	}
	while (low <= high) {
		mid = (low + high) / 2;
		int tmp_ret = 0;
		for (int num : v) {
			if (num % mid == 0) tmp_ret += (num / mid);
			else tmp_ret += (num / mid) + 1;
		}
		if (tmp_ret <= N) {
			ret = mid;
			high = mid - 1;
		}
		else if (tmp_ret > N) low = mid + 1;
	}
	cout << ret;
}