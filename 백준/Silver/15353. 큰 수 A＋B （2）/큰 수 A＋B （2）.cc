#include <iostream>
#include <string>
using namespace std;
string a, b, res = "";
int carry = 0;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> a >> b;
	int idx_a = a.size() - 1;
	int idx_b = b.size() - 1;
	while (1) {
		if (idx_a >= 0 and idx_b >= 0) {
			if (carry == 1) {
				res += to_string((a[idx_a] - '0' + b[idx_b] - '0' + 1) % 10);
				carry = (a[idx_a] - '0' + b[idx_b] - '0' + 1) / 10;
			}
			else {
				res += to_string((a[idx_a] - '0' + b[idx_b] - '0') % 10);
				carry = (a[idx_a] - '0' + b[idx_b] - '0') / 10;
			}
			idx_a--; idx_b--;
			if (idx_a == -1 and idx_b == -1) break;
		}
		else {
			if (idx_a == -1) {
				while (idx_b != -1) {
					if (carry) {
						res += to_string((b[idx_b] - '0' + 1) % 10);
						carry = (b[idx_b] - '0' + 1) / 10;
					}
					else res += b[idx_b];
					idx_b--;
				}
			}
			else if (idx_b == -1) {
				while (idx_a != -1) {
					if (carry) {
						res += to_string((a[idx_a] - '0' + 1) % 10);
						carry = (a[idx_a] - '0' + 1) / 10;
					}
					else res += a[idx_a];
					idx_a--;
				}
			}
			break;
		}
	}
	if (carry) res += "1";
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
}