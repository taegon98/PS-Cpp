#include <iostream>
using namespace std;

long long A, B, C, num;

long long my_pow(long long a, long long b) {
	if (b == 1) return a % C;

	long long ret = my_pow(a, b / 2);
	ret = ret * ret % C;
	if(b & 1) ret = ret * a % C;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> A >> B >> C;
	
	cout << my_pow(A, B);
	return 0;
}