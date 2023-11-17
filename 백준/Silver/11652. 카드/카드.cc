#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
unordered_map<ll, ll> mp;
vector<pair<ll, ll>> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll N, temp, max_val = -987654321, ret;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		mp[temp]++;
	}

	for (auto var : mp) {
		v.push_back(var);
	}

	sort(v.begin(), v.end());
	for (auto var : v) {
		if (var.second > max_val) {
			max_val = var.second;
			ret = var.first;
		}
	}
	cout << ret;
}