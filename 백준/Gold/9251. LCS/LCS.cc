#include <iostream>
using namespace std;
int arr[1004][1004];
string a, b;
int main() {
	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] != b[j-1]) arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
			else if (a[i-1] == b[j-1]) arr[i][j] = arr[i - 1][j - 1] + 1;
		}
	}
	cout << arr[a.size()][b.size()];
}