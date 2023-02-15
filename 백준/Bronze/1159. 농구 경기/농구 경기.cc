#include <iostream>

using namespace std;

int main() {
	int N, flag = 0;
	int arr[26] = { 0 };
	string s;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		arr[s[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] >= 5) {
			if (flag == 0) flag = 1;
			cout << (char)(i + 'a');
		}
	}

	if (flag == 0) cout << "PREDAJA";

	return 0;
}