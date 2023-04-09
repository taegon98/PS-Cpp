#include <iostream>
using namespace std;
bool is_prime[1004];
int main() {
	int N, K, ret = 0;
	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		if (!is_prime[i]) {
			for (int j = i; j <= N; j += i) {
				if (!is_prime[j]) {
					is_prime[j] = true; ret++;
					}
				if (ret == K) {
					cout << j; return 0;
				}
			}
		}
	}
}