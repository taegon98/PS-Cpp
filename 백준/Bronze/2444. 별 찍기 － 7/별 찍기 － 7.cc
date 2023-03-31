#include <iostream>
#include <algorithm>
using namespace std;
int N;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > i; j--) cout << " ";
		for (int j = 0; j < i * 2 + 1; j++) cout << "*";
		cout << "\n";
	}
	for (int i = N - 1; i > 0; i--) {
		for (int j = N; j > i; j--) cout << " ";
		for (int j = 2; j < i * 2 + 1; j++) cout << "*";
		cout << "\n";
	}
}