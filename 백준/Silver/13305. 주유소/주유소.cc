#include <iostream>
#include <vector>
using namespace std;
int n, m, cost, dp[100001];
vector<int> v1, v2;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> m;
		v1.push_back(m);
	}
	for (int i = 0; i < n; i++) {
		cin >> m;
		v2.push_back(m);
	}
	dp[0] = 0;
	dp[1] = v1[0] * v2[0];
	cost = v2[0];
	for (int i = 2; i < n; i++) {
		if (cost > v2[i - 1]) cost = v2[i - 1];
		dp[i] = dp[i - 1] + cost * v1[i - 1];
	}
	cout << dp[n - 1];
}