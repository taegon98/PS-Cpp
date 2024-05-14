#include <iostream>
using namespace std;
long long n;
long long arr[104];
int main() {
	cin >> n;
	arr[0] = 0; arr[1] = 1;
	for (int i = 2; i <= n; i++) arr[i] = arr[i - 2] + arr[i - 1];
	cout << arr[n];
}