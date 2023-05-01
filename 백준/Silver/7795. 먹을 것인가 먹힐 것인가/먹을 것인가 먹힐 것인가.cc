#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A, B;
int T, N, M, tmp;

int bin(int left, int right) {
	int cnt = 0;
	for (int num : A) {
		int low = left, high = right, mid;
		int initial_value = (low + high) / 2;
		while (low <= high) {
			mid = (low + high) / 2;
			if (num <= B[mid]) high = mid - 1;
			else if (num > B[mid]) low = mid + 1;
		}
		cnt += (high + 1);
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
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

		cout << bin(0, M - 1) << "\n"; //A기준 B 이분탐색
	}
}