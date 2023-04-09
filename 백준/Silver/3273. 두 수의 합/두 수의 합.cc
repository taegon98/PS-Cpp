#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, tmp, p1, p2, ret;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	p1 = 0; p2 = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> tmp; v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cin >> x;
	while (1) {
		if (p1 >= p2) break;
		tmp = v[p1] + v[p2];
		if (tmp == x) {
			ret++;
			p1++; p2--;
		}
		else if (tmp < x) p1++;
		else if (tmp > x) p2--;
	}
	cout << ret;
}