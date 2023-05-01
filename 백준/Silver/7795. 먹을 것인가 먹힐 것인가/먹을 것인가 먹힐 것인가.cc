#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A, B;
int T, N, M, tmp, ret;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ret = 0;
		A.clear(); B.clear();
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			A.push_back(tmp);
		}
		for (int i = 0; i < M; i++) {
			cin >> tmp;
			B.push_back(tmp);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		for (int num : A) {
			auto pos = lower_bound(B.begin(), B.end(), num);
			ret += (int)(pos - B.begin());
		}
		cout << ret << "\n";
	}
}