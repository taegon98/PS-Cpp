#include <iostream>
using namespace std;
int N, tmp;
string str;
bool digit[24] = { false };

int main() {
	cin >> N;
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int j = 0; j < N; j++) {
		cin >> str;
		if (str == "all") {
			for (int i = 1; i <= 20; i++) digit[i] = true;
			continue;
		}
		else if (str == "empty") {
			for (int i = 1; i <= 20; i++) digit[i] = false;
			continue;
		}
		cin >> tmp;
		if (str == "add") digit[tmp] = true;
		else if (str == "check") cout << digit[tmp] << "\n";
		else if (str == "remove") digit[tmp] = false;
		else if (str == "toggle") {
			if (digit[tmp]) digit[tmp] = false;
			else digit[tmp] = true;
		}
	}
}