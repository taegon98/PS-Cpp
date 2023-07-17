#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<ll> v;
ll n, pos;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pos;
		v.push_back(pos);
	}
	sort(v.begin(), v.end());
	cout << v[(n - 1) / 2];
}