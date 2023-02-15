#include <iostream>
#include <string>

using namespace std;

int main() {
	string s, ans = "";

	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 and s[i] <= 90) {
			if (s[i] + 13 > 90) ans += s[i] + 13 - 26;
			else ans += s[i] + 13;
		}
		else if (s[i] >= 97 and s[i] <= 122) {
			if (s[i] + 13 > 122) ans += s[i] + 13 - 26;
			else ans += s[i] + 13;
		}
		else {
			ans += s[i];
		}
	}
	cout << ans;

	return 0;
}