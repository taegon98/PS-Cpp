#include <iostream>
#include <algorithm>
using namespace std;
int N, K, arr[1004];
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	cout << arr[N - K];
}