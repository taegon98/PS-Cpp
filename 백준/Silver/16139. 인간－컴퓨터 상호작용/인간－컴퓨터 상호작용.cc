#include <iostream>
#include <unordered_map>
using namespace std;
string s;
int q, idx, l, r, psum[200001][27];
unordered_map<int, int> mp;
char ch;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s >> q;

	for (int i = 0; i < s.size(); i++) {
		idx = s[i] - 'a';

		if (mp.find(idx) == mp.end()) {
			for (int j = 0; j < i; j++)
				psum[j][idx] = 0;
			psum[i][idx] = 1;
		}
		else {
			for (int j = mp[idx] + 1; j < i; j++)
				psum[j][idx] = psum[mp[idx]][idx];
			psum[i][idx] = psum[mp[idx]][idx] + 1;
		}
		mp[idx] = i;
	}

	for (auto var : mp) {
		for (int i = var.second; i < s.size(); i++) {
			psum[i][var.first] = psum[var.second][var.first];
		}
	}

	for (int i = 0; i < q; i++) { 
		cin >> ch >> l >> r;
		idx = ch - 'a';

		if (!l) cout << psum[r][idx] << "\n";
		else if (psum[l][idx] == psum[l - 1][idx])
			cout << psum[r][idx] - psum[l][idx] << "\n";
		else if (psum[l][idx] != psum[l - 1][idx])
			cout << psum[r][idx] - psum[l][idx] + 1 << "\n";
	}
}