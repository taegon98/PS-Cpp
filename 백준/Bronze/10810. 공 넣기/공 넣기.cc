#include <iostream>
using namespace std;
int N, M, i, j, k, arr[104];
int main() {
	cin >> N >> M;
	for (int n = 1; n <= M; n++) {
		cin >> i >> j >> k;
		for (int m = i; m <= j; m++) arr[m] = k;
	}
	for (int n = 1; n <= N; n++)cout << arr[n] << " ";
}