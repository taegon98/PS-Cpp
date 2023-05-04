#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, tmp, idx, ret = -987654321, dp[1004];
vector<int> v, v_ret;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	for (int i = 0; i < n; i++) {
		int len = 1;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) len = max(len, dp[j] + 1);
		}
		dp[i] = len;
		if (ret < dp[i]) {
			ret = dp[i];
			idx = i;
		}
	}
	cout << ret << "\n";
	ret--;
	v_ret.push_back(v[idx]);
	for (int i = idx; i >= 0; i--) {
		if (dp[i] == ret) {
			v_ret.push_back(v[i]);
			ret--;
		}
	}
	reverse(v_ret.begin(), v_ret.end());
	for (auto a : v_ret) cout << a << " ";
}