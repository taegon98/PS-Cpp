#include <iostream>
using namespace std;

int gcd(int a, int b) {

	if (b == 0) return a;
	int temp = a;

	a = b;
	b = temp % b;
	return gcd(a, b);
}
int main() {
	string s1, s2, temp1, temp2;
	int n;
	cin >> s1 >> s2;

	n = s1.size() * s2.size() / gcd(s1.size(), s2.size());
	
	while (temp1.size() != n) temp1 += s1;
	while (temp2.size() != n) temp2 += s2;
	
	if (temp1 != temp2) cout << 0;
	else cout << 1;
}