#include <iostream>
using namespace std;
int T;
string s;

bool go(int l, int r) {
	while (l <= r) {
		if (s[l] == s[r]) {
			l++; r--;
		}
		else return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> s;

		int flag = 0;
		int l = 0, r = s.size() - 1;

		while (l <= r) {
			if (s[l] == s[r]) {
				l++; r--;
			}
			else {
				flag = 1;
				if (s[l] == s[r - 1]) {
					if (go(l + 1, r - 2)) break;
				}
				if (s[l + 1] == s[r]) {
					if (go(l + 2, r - 1)) break;
				}
				if (r < s.size() - 1 and s[l] == s[r + 1]) {
					if (go(l + 1, r)) break;
				}
				if (l > 0 and s[l - 1] == s[r]) {
					if (go(l, r - 1)) break;
				}
				flag = 2;
				break;
			}
		}
		cout << flag << "\n";
	}
}