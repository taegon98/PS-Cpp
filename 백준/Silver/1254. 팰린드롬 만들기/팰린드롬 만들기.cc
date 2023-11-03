#include <iostream>
#include <algorithm>
using namespace std;
string s1, s2, temp;

bool check() {
	int l = 0, r = s1.size() - 1;

	while (l <= r) {
		if (s1[l] != s1[r]) return false;
		l++; r--;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s1;
	temp = s1;
	int idx = 0;

	while (1) {

		if (!check()) {
			s2 += s1[idx++];
			reverse(s2.begin(), s2.end());
			s1 = temp;
			s1 += s2;
		}
		else {
			cout << s1.size();
			return 0;
		}
		reverse(s2.begin(), s2.end());
	}
}