#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string s;
	int alpha[26] = { 0 };

	cin >> s;

	for (char c : s) alpha[c - 97]++;
	for (int i : alpha) cout << i << " ";
}