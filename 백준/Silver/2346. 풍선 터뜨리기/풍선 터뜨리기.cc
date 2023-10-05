#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, num, p = 0;
	vector<int> answer;
	vector<pair<int, int>> v;

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> num;
		v.push_back({ 1, num });
	}

	while (1) {
		answer.push_back(p + 1);

		if (answer.size() == n) break;
		v[p].first = 0;
		int cnt = 0, target = v[p].second;

		if (target > 0) {
			while (cnt != target) {
				p++;
				if (p >= n) p = 0;
				if (v[p].first == 1) cnt++;
			}
		}
		else {
			target *= -1;
			while (cnt != target) {
				p--;
				if (p < 0) p = n - 1;
				if (v[p].first == 1) cnt++;	
			}
		}
	}
	for (auto var : answer) cout << var << " ";
}