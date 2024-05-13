#include <iostream>]
using namespace std;

int t, P, Q, R, S, W;

int main() {
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> P >> Q >> R >> S >> W;

		int a = P * W;
		int b = Q;

		if (W > R) {
			b += (W - R) * S;
		}
		cout << "#" << tc << " " << min(a, b) << "\n";
	}
}