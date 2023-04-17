#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, L, s, e, ret, tmp, idx;
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end());
	for (pair<int, int> p : v) {
		if (idx >= p.second) continue;
		if (idx < p.first) {
			tmp = (p.second - p.first) / L;
			if ((p.second - p.first) % L != 0) tmp += 1;
			idx = p.first + tmp * L;
		}
		else {
			tmp = (p.second - idx) / L;
			if ((p.second - idx) % L != 0)tmp += 1;
			idx = idx + tmp * L;
		}
		ret += tmp;
	}
	cout << ret;
}