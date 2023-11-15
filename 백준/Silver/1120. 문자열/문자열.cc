#include <iostream>
using namespace std;
string s1, s2;
int ret = 987654321;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s1 >> s2;

	int diff = s2.size() - s1.size();

	for (int i = 0; i <= diff; i++) {
		int cnt = 0;
		for (int j = 0; j < s1.size(); j++) {
			if (s1[j] != s2[i + j]) cnt++;
		}
		ret = min(ret, cnt);
	}
	cout << ret;
}