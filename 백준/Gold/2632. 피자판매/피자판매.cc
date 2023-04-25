#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int s, n, m, ret;
int arr1[1004], arr2[1004], psum1[2004], psum2[2004];
unordered_map<int, int> mp1, mp2;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr1[i];
		psum1[i] = psum1[i - 1] + arr1[i];
	}
	for (int i = n + 1; i <= n * 2; i++) {
		psum1[i] = psum1[i - 1] + arr1[i - n];
	}
	for (int i = 1; i <= m; i++) {
		cin >> arr2[i];
		psum2[i] = psum2[i - 1] + arr2[i];
	}
	for (int i = m + 1; i <= m * 2; i++) {
		psum2[i] = psum2[i - 1] + arr2[i - m];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n + i - 1; j++) {
			mp1[psum1[j] - psum1[j - i]]++;
			if (i == n) break;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = i; j <= m + i - 1; j++) {
			mp2[psum2[j] - psum2[j - i]]++;
			if(i == m) break;
		}
	}
	ret = mp1[s] + mp2[s];
	for (int i = 1; i < s; i++) ret += (mp1[i] * mp2[s - i]);
	cout << ret;
}