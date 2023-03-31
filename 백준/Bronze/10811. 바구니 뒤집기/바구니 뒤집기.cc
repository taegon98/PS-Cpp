#include <iostream>
#include <algorithm>
using namespace std;
int N, M, a, b, arr[104];
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) arr[i] = i;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		reverse(arr + a, arr + b + 1);
	}
	for (int i = 1; i <= N; i++)cout << arr[i] << " ";
}