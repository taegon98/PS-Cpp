#include <iostream>
using namespace std;

int N, K;

int factorial(int n) {
	if (n == 0 or n == 1) return 1;
	return n * factorial(n - 1);
}

int main() {
	cin >> N >> K;
	cout << factorial(N) / (factorial(N - K) * factorial(K));
}