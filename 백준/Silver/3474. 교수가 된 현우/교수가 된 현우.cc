#include <iostream>
using namespace std;

int main() {
	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL); cout.tie(NULL);
		cin >> N;
		int ret = 0, num = 5;

		while (num <= N) {
			ret = ret + (N / num);
			num *= 5;
		}
		cout << ret << "\n";
	}
	return 0;
}