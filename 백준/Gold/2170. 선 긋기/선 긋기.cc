#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, tmp1, tmp2, s, e, ret;
vector<pair<ll, ll>> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		v.push_back({ tmp1,tmp2 });
	}
	sort(v.begin(), v.end());
	s = v[0].first; e = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].first <= e) e = v[i].second > e ? v[i].second : e;
		else if (v[i].first > e) {
			ret += (e - s);
			s = v[i].first; e = v[i].second;
		}
	}
	ret += (e - s);
	cout << ret;
}