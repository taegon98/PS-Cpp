#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, s, e, t, ret = 1;
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back({ e,s });
	}
	sort(v.begin(), v.end());
	t = v.front().first;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].second >= t) {
			ret++; t = v[i].first;
		}
	}
	cout << ret;
}