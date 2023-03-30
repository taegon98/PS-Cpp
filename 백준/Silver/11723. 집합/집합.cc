#include <iostream>
using namespace std;
int N, num, tmp;
string str;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> str;
		if (str == "all") {
			num = (1 << 20) - 1; continue;
		}
		else if (str == "empty") {
			num = 0; continue;
		}
		cin >> tmp;
		if (str == "add") num |= (1 << tmp - 1);
		else if (str == "check") {
			if (num & (1 << tmp - 1)) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "remove") num &= ~(1 << tmp - 1);
		else if (str == "toggle") num ^= (1 << tmp - 1);
	}
}