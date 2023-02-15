#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int psum[100001];

int main() {
	int N, K, max, tmp;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		psum[i] = psum[i - 1] + tmp;
	}
	
	max = psum[K] - psum[0];
	for (int i = K+1; i <= N; i++) {
		if (psum[i] - psum[i - K] > max) max = psum[i] - psum[i - K];
	}

	cout << max;
	
	return 0;
}