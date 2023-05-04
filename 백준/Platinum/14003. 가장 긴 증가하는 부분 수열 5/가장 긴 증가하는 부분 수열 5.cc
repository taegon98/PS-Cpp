#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, target, pos, len, dp[1000004];
vector<int> ret;
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> target;
		auto p = lower_bound(dp, dp + len, target);
		int pos = p - dp;
		if (*p == 0) len++;
		*p = target;
		v.push_back({ target,pos + 1 });
	}
	cout << len << "\n";
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == len) {
			for (int j = i; j >= 0; j--) {
				if (v[j].second == len) {
					ret.push_back(v[j].first);
					len--;
				}
			}
			break;
		}
	}
	reverse(ret.begin(), ret.end());
	for (int num : ret) cout << num << " ";
}