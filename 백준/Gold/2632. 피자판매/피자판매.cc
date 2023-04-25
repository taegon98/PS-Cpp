#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int s, n, m, tmp, ret;
int arr1[1004], arr2[1004];
vector<int> v1, v2;
unordered_map<int, int> mp1, mp2;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i]; tmp += arr1[i];
	}
	v1.push_back(tmp);
	tmp = 0;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i]; tmp += arr2[i];
	}
	v2.push_back(tmp);
	tmp = 0;
	for (int i = 0; i < n; i++) {
		int tot = 0;
		int idx = i;
		for (int j = 1; j < n; j++) {
			tot += arr1[idx];
			v1.push_back(tot);
			idx = (idx + 1) % n;
		}
	}
	for (int i = 0; i < m; i++) {
		int tot = 0;
		int idx = i;
		for (int j = 1; j < m; j++) {
			tot += arr2[idx];
			v2.push_back(tot);
			idx = (idx + 1) % m;
		}
	}
	for (int num : v1) mp1[num]++;
	for (int num : v2) mp2[num]++;
	for (pair<int, int> p : mp1) {
		tmp = s - p.first;
		if (p.first == s) ret = ret + p.second;
		else if (mp2[tmp]) ret = ret + (p.second * mp2[tmp]);
	}
	for (pair<int, int> p : mp2) {
		if (p.first == s) ret = ret + p.second;
	}
	cout << ret;
}