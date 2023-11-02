#include <iostream>
using namespace std;
string s, t;

bool split(char deli) {
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == deli) {
			t = t.substr(i + 1);
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (cin >> s >> t) {

		int i = 0;
		for (; i < s.size(); i++) {
			if (!split(s[i])) {
				cout << "No\n";
				break;
			}
		}
		if (i == s.size()) cout << "Yes\n";
	}
}