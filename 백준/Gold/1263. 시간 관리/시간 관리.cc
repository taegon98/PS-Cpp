#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, T, S, ret, pre;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first > b.first;
	}
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> T >> S;
		v.push_back({ T,S });
	}
	sort(v.begin(), v.end(), cmp);
	ret = v[0].second - v[0].first;
	pre = v[0].second;

	for (int i = 1; i < N; i++) {
		if (pre + v[i].first > v[i].second) {
			ret = ret - (pre + v[i].first - v[i].second);
			pre = v[i].second;
		}
		else {
			pre += v[i].first;
		}
		if (ret < 0) {
			cout << -1;
			exit(0);
		}
	}
	cout << ret;
}