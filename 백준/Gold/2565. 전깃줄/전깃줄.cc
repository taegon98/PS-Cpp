#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, tmp1, tmp2, ret = -987654321, dp[104];
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2;
		v.push_back({ tmp1,tmp2 });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int len = 1;
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second) {
				len = max(len, dp[j] + 1);
			}
		}
		dp[i] = len;
		ret = max(ret, dp[i]);
	}
	cout << n - ret;
}