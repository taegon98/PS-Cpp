#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
int N;
string s;

string split(string str) {
	auto pos = str.find(".");
	return str.substr(pos + 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		mp[split(s)]++;
	}
	for (auto var : mp) {
		cout << var.first << " " << var.second << "\n";
	}
}