#include <iostream>

using namespace std;
int n;

int check(string temp) {
	for (int i = 0; i < temp.size() / 2; i++) {
		if (temp[i] != temp[temp.size() - 1 - i]) return 0;
	}
	return 1;
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		cin >> n;
		string s;
		char arr[9][9];
		int ret = 0;

		for (int i = 0; i < 8; i++) {
			cin >> s;
			for (int j = 0; j < 8; j++) {
				arr[i][j] = s[j];
			}
		}

		for (int r = 0; r < 8; r++) {
			for (int i = 0; i < 8 - n + 1; i++) {
				string temp = "";
				for (int j = i; j < i + n; j++) {
					temp += arr[r][j];
				}
				ret += check(temp);
			}
		}


		for (int c = 0; c < 8; c++) {
			for (int i = 0; i < 8 - n + 1; i++) {
				string temp = "";
				for (int j = i; j < i + n; j++) {
					temp += arr[j][c];
				}
				ret += check(temp);
			}
		}
		cout << "#" << tc << " " << ret << "\n";
	}
}