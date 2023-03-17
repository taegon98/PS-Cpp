#include <iostream>
#include <vector>
using namespace std;

int main() {
	int X, N, cost, cnt, tot = 0;
	cin >> X;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cost >> cnt;
		tot += cost * cnt;
	}
	if (X == tot)cout << "Yes";
	else cout << "No";
	return 0;
}