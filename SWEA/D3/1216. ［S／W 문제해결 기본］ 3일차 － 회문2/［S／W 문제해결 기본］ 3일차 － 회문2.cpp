#include <iostream>
#include <algorithm>
using namespace std;
int N, ret, temp;
char arr[101][101];
string s;

void get_odd(string  s) {

	for (int i = 0; i < s.size(); i++) {
		int l = i - 1, r = i + 1, temp = 1;

		while (1) {
			if (l < 0 or r >= 100) break;
			else if (s[l] != s[r]) break;
			temp += 2;
			l--; r++;
		}
		ret = max(ret, temp);
	}
}

void get_even(string  s) {

	for (int i = 0; i < s.size() - 1; i++) {
		int temp = 1;
		int idx = i + 1;
		while (s[i] == s[idx]) {
			temp++;
			idx++;
		}
		if (temp % 2 == 1) {
			temp--;
			idx--;
		}
		if (temp > 1) {

			int l = i - 1, r = idx;

			while (1) {
				if (l < 0 or r >= 100) break;
				else if (s[l] != s[r]) break;
				temp += 2;
				l--; r++;
			}
		}
		ret = max(ret, temp);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int tc = 1; tc <= 10; tc++) {
		cin >> N;
		ret = 0;

		for (int i = 0; i < 100; i++) {
			cin >> s;
			for (int j = 0; j < 100; j++) {
				arr[i][j] = s[j];
			}
		}

		for (int i = 0; i < 100; i++) {
			
			for (int k = 0; k < 2; k++) {
				string temp = "";
				for (int j = 0; j < 100; j++) {
					if (k) temp += arr[j][i];
					else temp += arr[i][j];
				}
				get_odd(temp);
				get_even(temp);
			}
			
			
		}
		cout << "#" << tc << " " << ret << "\n";
	}
}