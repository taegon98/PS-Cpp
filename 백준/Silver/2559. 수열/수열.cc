#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[100001];
int psum[100001];

int main() {
	int N, K, max;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	
	max = psum[K] - psum[0];
	for (int i = K+1; i <= N; i++) {
		if (psum[i] - psum[i - K] > max) max = psum[i] - psum[i - K];
	}

	cout << max;
	
	return 0;
}