#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i += 4) {
		cout << "long ";
	}
	cout << "int";
}