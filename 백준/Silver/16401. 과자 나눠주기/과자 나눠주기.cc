#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, N, num, low = 1, high = -987654321, mid, ret = 0;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		v.push_back(num);
		high = max(high, num);
	}

	while (low <= high) {
		mid = (low + high) / 2;
		int temp = 0;
		for (auto var : v) {
			temp += (var / mid);
		}
		if (temp < M) high = mid - 1;
		else if (temp >= M) {
			low = mid + 1;
			ret = max(ret, mid);
		}
	}
	cout << ret;
}