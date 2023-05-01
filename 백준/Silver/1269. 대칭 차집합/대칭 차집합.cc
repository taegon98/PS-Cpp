#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
ll A, B, tmp, ret;
vector<ll> v1, v2;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B;
	for (int i = 0; i < A; i++) {
		cin >> tmp;
		v1.push_back(tmp);
	}
	for (int i = 0; i < B; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}
	set<ll> s1(v1.begin(), v1.end());
	set<ll> s2(v2.begin(), v2.end());
	v1.clear(); v2.clear();
	for (auto num : s1) v1.push_back(num);
	for (auto num : s2) v2.push_back(num);
	
	for (int target : v1) {
		if (!binary_search(v2.begin(), v2.end(), target)) ret++;
	}
	for (int target : v2) {
		if (!binary_search(v1.begin(), v1.end(), target)) ret++;
	}
	cout << ret;
}