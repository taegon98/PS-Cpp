#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c;
vector<int> v(3);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> v[0] >> v[1] >> v[2];
		if (v[0] == 0 and v[1] == 0 and v[2] == 0) break;
		sort(v.begin(), v.end());

		if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) cout << "right\n";
		else cout << "wrong\n";
	}
}