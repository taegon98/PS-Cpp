#include <iostream>
using namespace std;
int main() {
	string s;
	int idx = 0;
	cin >> s;
	while (1) {
		if (s[idx] == 'p' and s[idx + 1] == 'i') idx += 2;
		else if (s[idx] == 'k' and s[idx + 1] == 'a') idx += 2;
		else if (s[idx] == 'c' and s[idx + 1] == 'h' and s[idx + 2] == 'u') idx += 3;
		else break;
		if (idx == s.size()) break;
	}
	if (idx != s.size()) cout << "NO";
	else cout << "YES";
}