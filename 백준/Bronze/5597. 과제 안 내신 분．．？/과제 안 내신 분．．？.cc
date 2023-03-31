#include <iostream>
using namespace std;
bool arr[34];
int main() {
	int tmp;
	for (int i = 1; i <= 28; i++) {
		cin >> tmp; arr[tmp] = true;
	}
	for (int i = 1; i <= 30; i++) if (!arr[i]) cout << i << "\n";
}