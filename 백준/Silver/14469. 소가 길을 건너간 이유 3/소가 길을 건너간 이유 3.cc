#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, s, t, ret;
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		v.push_back({ s,t });
	}
	sort(v.begin(), v.end());
	ret = v.front().first + v.front().second;
	for (int i = 1; i < v.size(); i++) {
		ret = max(v[i].first, ret);
		ret += v[i].second;
	}
	cout << ret;
}