#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int tmp, tot = 0;
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		cin >> tmp; v.push_back(tmp);
		tot += tmp;
	}
	sort(v.begin(), v.end());
	cout << tot / 5 << "\n" << v[2];
}