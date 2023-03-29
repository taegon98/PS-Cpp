#include <iostream>
using namespace std;
int main() {
	int X, l = 64, cnt = 0, ret = 0, size = 0;
	cin >> X;
	while (1) {
		if (size == X or l == X) break;
		l /= 2;
		if (size + l <= X) {
			ret++;
			size += l;
		}
	}
	if (ret == 0) cout << 1;
	else cout << ret;
}