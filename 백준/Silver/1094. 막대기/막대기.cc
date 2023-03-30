#include <iostream>
using namespace std;
int main() {
	int X, ret = 0;
	cin >> X;
	while (X) {
		if (X % 2 == 1) ret++;
		X /= 2;
	}
	cout << ret;
}