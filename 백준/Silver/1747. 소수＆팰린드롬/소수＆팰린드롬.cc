#include <iostream>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
ll N;

bool is_prime(ll n) {
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool is_palin(string s) {
	ll l = 0, r = s.size() - 1;

	while (l <= r) {
		if (s[l] != s[r]) return false;
		l++; r--;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	if (N == 1) N++;
	while (1) {
		if (is_prime(N) and is_palin(to_string(N))) {
			cout << N;
			exit(0);
		}
		else N++;
	}	
}