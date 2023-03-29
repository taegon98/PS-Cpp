#include <iostream>
using namespace std;

int main() {
	int X, l = 64, cnt = 0, ret = 0;
	int size = 0;
	cin >> X;
	if (X == 64) {
		cout << 1; return 0;
	}
	while (1) {
		l /= 2;
		if (size + l <= X) {
			ret++;
			size += l;
		}
		if (size == X) break;
	}
	cout << ret;
}