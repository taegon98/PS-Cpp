#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, M, target;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			cin >> target;
			v.push_back(target);
		}
		sort(v.begin(), v.end());
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> target;
			if (binary_search(v.begin(), v.end(), target)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
}