#include <iostream>
using namespace std;
int main() {
	int N, M, a, b, arr[104];
	cin >> N >> M;
	for (int i = 1; i <= 100; i++) arr[i] = i;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		swap(arr[a], arr[b]);
	}
	for (int i = 1; i <= N; i++)cout << arr[i] << " ";
}