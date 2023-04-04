#include <iostream>
#include <string>
using namespace std;
string a, b, res = "";
int carry = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> a >> b;
	while (1) {
		int sum = 0;
		if (a.size()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		res += to_string((sum + carry) % 10);
		carry = (sum + carry) / 10;
		if (!a.size() and !b.size()) break;
	}
	if (carry) res += "1";
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
}