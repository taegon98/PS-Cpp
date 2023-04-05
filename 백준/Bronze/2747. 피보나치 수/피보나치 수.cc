#include <iostream>
using namespace std;
int fibo[1004];

int main() {
	int n;
	cin >> n;
	fibo[0] = 0; fibo[1] = 1;

	for (int i = 2; i <= n; i++) fibo[i] = fibo[i - 2] + fibo[i - 1];
	cout << fibo[n];
}