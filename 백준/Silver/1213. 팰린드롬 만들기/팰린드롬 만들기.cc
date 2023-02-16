#include <iostream>

using namespace std;

int alpha[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	char ch;
	int flag = 0, p1, p2;

	cin >> s;
	p1 = 0, p2 = s.size() - 1;

	for (int i = 0; i < s.size(); i++) {
		alpha[s[i] - 'A']++;
	}
	
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 0) continue;
		if (alpha[i] & 1) {
			ch = i + 'A';
			s[s.size() / 2] = ch;
			alpha[i]--;
			flag++;
		}
		if (!(alpha[i] & 1)) {
			for (int j = 0; j < alpha[i] / 2; j++) {
				s[p1++] = i + 'A';
				s[p2--] = i + 'A';
			}
		}
		if (flag > 1) break;
	}
	
	if (flag <= 1) {
		cout << s << "\n";
	}
	else cout << "I'm Sorry Hansoo\n";
	return 0;
}