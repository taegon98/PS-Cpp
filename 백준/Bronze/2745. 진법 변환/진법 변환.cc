#include <iostream>
#include <cmath>
using namespace std;
int main() {
	string N;
	long long B, ret = 0, exp = 0;
	cin >> N >> B;
	for (int i = N.size() - 1; i >= 0; i--) {
		int num = pow(B, exp++);
		if (isalpha(N[i])) ret += ((N[i] - 55) * num);
		else ret += (N[i] - '0') * num;
	}
	cout << ret;
}