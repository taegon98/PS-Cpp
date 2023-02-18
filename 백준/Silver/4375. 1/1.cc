#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int n;
	
	while (scanf("%d", &n) != EOF) {
		int cnt = 1;
		long long m = 1;

		while (1) {
			if (m % n == 0) break;
			m = (m * 10 + 1) % n;
			cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}