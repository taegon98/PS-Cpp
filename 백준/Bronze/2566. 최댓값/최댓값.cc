#include <iostream>
using namespace std;
int arr[10][10], tmp, ret = -987654321, r, c;
int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> tmp;
			if (tmp > ret) {
				ret = tmp;
				r = i; c = j;
			}
		}
	}
	cout << ret << "\n";
	cout << r << " " << c;
}