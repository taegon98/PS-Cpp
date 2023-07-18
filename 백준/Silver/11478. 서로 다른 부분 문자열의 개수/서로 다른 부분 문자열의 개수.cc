#include <iostream>
#include <map>
using namespace std;
string s;
map<string, int> mp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;

	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j <= s.size() - i; j++) {
			mp[s.substr(j, i)]++;
		}
	}
	cout << mp.size();
}