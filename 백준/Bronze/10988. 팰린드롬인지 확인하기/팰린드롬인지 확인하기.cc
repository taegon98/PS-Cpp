#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	register int mid, flag = 1;
	char p1, p2;
	string s;

	cin >> s;

	if (s.size() % 2 == 1) mid = s.size() / 2;
	else mid = s.size() / 2 + 1;

	for (int i = 0; i < mid; i++) {
		p1 = s[i];
		p2 = s[s.size() - (i + 1)];

		if (p1 != p2) {
			flag = 0; break;
		}
	}

	if (flag == 1) cout << 1;
	else cout << 0;

	return 0;
}