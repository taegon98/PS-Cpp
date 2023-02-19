#include <iostream>
using namespace std;

int main() {
	int N;
	long long ans = 1;

	cin >> N;
	
	for (int i = N; i > 1; i--) {
		ans *= i;
	}
	cout << ans;

	return 0;
}