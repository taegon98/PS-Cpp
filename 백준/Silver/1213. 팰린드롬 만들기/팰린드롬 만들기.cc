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
		if (alpha[i] % 2 == 1) {
			ch = i + 'A';
			alpha[i]--;
			flag++;
		}
		if (flag > 1) break;
	}

	if (flag <= 1) {
		if (s.size() % 2 == 1) s[s.size() / 2] = ch;
		
		for (int i = 0; i < 26; i++) {
			if (alpha[i] != 0 and alpha[i] % 2 == 0) {
				for (int j = 0; j < alpha[i] / 2; j++) {
					s[p1++] = i + 'A';
					s[p2--] = i + 'A';
				}
			}
		}
		cout << s << "\n";
	}
	else cout << "I'm Sorry Hansoo\n";
	
	return 0;
}