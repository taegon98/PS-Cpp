#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int T;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> s;
		stack<char> _s, temp;

		for (int i = 0; i < s.size(); i++) {
			if ((s[i] >= 97 and s[i] <= 122) or
				(s[i] >= 65 and s[i] <= 90) or
				(s[i] - '0' >= 0 and s[i] - '0' <= 9)) {
				_s.push(s[i]);
			}
			else if (s[i] == '<') {
				if (_s.size()) {
					temp.push(_s.top());
					_s.pop();
				}
			}
			else if (s[i] == '>') {
				if (temp.size()) {
					_s.push(temp.top());
					temp.pop();
				}
			}
			else if (s[i] == '-' and _s.size())
				_s.pop();
		}

		vector<char> v;

		while (_s.size()) {
			v.push_back(_s.top());
			_s.pop();
		}
		reverse(v.begin(), v.end());
		while (temp.size()) {
			v.push_back(temp.top());
			temp.pop();
		}
		for (auto var : v) cout << var;
		cout << "\n";
	}
}