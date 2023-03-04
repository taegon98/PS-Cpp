#include <iostream>
using namespace std;

int main() {
	string input;
	cin >> input;

	while (input != "end") {
		bool flag1 = false, flag2 = true, flag3 = true;
		int v = 0, c = 0;
		char prev = ' ';

		for (int i = 0; i < input.size(); i++) {
			if ((prev != 'e' and prev != 'o') and prev == input[i]) {
				flag3 = false;
				break;
			}
			if (input[i] == 'a' or input[i] == 'e' or input[i] == 'i' or input[i] == 'o' or input[i] == 'u') {
				flag1 = true;
				v++; c = 0;
			}
			else {
				c++; v = 0;
			}
			if (v == 3 or c == 3) {
				flag2 = false;
				break;
			}

			prev = input[i];
		}

		if (flag1 and flag2 and flag3) cout << "<" << input << ">" << " is acceptable.\n";
		else cout << "<" << input << ">" << " is not acceptable.\n";

		cin >> input;
	}
	return 0;
}