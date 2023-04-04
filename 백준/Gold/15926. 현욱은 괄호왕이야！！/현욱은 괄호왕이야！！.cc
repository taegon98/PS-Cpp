#include <iostream>
#include <stack>
using namespace std;
int n, tmp = 1, cnt = 0, ret = -987654321;
string str;
int dp[200004];
stack<int> s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] == '(') s.push(i);
		else if (!s.empty() and str[i] == ')') {
			dp[s.top()] = 1;
			dp[i] = 1;
			s.pop();
		}
	}
	for (int i = 0; i < n; i++) {
		if (dp[i] == 1) cnt++;
		else {
			ret = max(ret, cnt);
			cnt = 0;
		}
	}
	cout << max(ret, cnt);
}