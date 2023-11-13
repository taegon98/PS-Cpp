#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int N;

bool is_prime(int num) {
	
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void go(int depth, int num) {

	if (depth == N) {
		cout << num << "\n";
		return;
	}

	num *= 10;
	for (int i = 1; i < 10; i++) {
		if (i % 2 == 0) continue;
		
		num += i;
		if (num % 2 == 0 or !is_prime(num)) {
			num -= i;
			continue;
		}
		go(depth + 1, num);
		num -= i;
	}
	num /= 10;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	go(1, 2);
	go(1, 3);
	go(1, 5);
	go(1, 7);
}