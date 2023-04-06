#include <iostream>
using namespace std;
int main() {
	int A, B, C; cin >> A >> B >> C;
	if (A == 60 and B == 60 and C == 60) cout << "Equilateral";
	else if ((A + B + C == 180) and
		(A == B and A != C) or 
		(A == C and A != B) or
		(B == C and B != A)) cout << "Isosceles";
	else if (A + B + C == 180 and A != B and A != C and B != C) cout << "Scalene";
	else if (A + B + C != 180)cout << "Error";
}