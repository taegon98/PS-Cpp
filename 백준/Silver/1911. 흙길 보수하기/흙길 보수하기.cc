#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, L, s, e, ret, tmp;
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
		if (tmp < p.first) tmp = p.first;
		while (tmp < p.second) ret++, tmp += L;
	}
	cout << ret;
}