#include <iostream>
using namespace std;
string s;
int tot_0, tot_1;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> s;
	int pre = -1;

	for (int i = 0; i < s.size(); i++) {
		if (pre != 0 and s[i] == '0') {
			tot_0++;
			pre = 0;
		}
		else if (pre != 1 and s[i] == '1') {
			tot_1++;
			pre = 1;
		}
	}
	cout << min(tot_0, tot_1);
}