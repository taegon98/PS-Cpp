#include <iostream>
using namespace std;

int main() {
	int N, M, J, idx, s, e, ret = 0;

	cin >> N >> M;
	s = 1, e = M;
	cin >> J;

	for (int i = 0; i < J; i++) {
		cin >> idx;
		
		if (s <= idx and  e >= idx) continue;
		else if (e < idx) {
			while (e != idx) {
				s++; e++; ret++;
			}
		}
		else {
			while (s != idx) {
				s--; e--; ret++;
			}
		}
	}
	cout << ret;
	return 0;
}