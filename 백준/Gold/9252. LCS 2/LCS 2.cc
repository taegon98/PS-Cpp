#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s1, s2;
int lcs[1004][1004], ret, y, x;
vector<char> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s1 >> s2;
	y = s2.size(); x = s1.size();
	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s1[j - 1] == s2[i - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
		}
	}
	ret = lcs[y][x];
	cout << ret << "\n";
	while (ret) {
		if (y <= 0 or x <= 0) break;
		if (lcs[y][x] == lcs[y][x - 1]) x -= 1;
		else if (lcs[y][x] == lcs[y - 1][x]) y -= 1;
		else {
			x -= 1;
			y -= 1;
			v.push_back(s1[x]);
			ret--;
		}
	}
	reverse(v.begin(), v.end());
	for (auto a : v) cout << a;
}