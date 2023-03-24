#include <iostream>
using namespace std;

int main() {
	while (1) {
		string n;
		cin >> n;

		if (n == "0") break;
		bool ok = true;
		for (int i = 0; i < n.size() / 2; i++) {
			if (n[i] != n[n.size() - i - 1]) {
				ok = false;
				break;
			}
		}
		if (ok) cout << "yes\n";
		else cout << "no\n";
	}
}