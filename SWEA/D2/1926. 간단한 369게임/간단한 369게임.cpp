#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
vector<string> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int cnt = 0, temp = i;
		while (temp) {
			int rem = temp % 10;
			if (rem == 3 or rem == 6 or rem == 9) cnt++;
			temp /= 10;
		}

		if (!cnt) v.push_back(to_string(i) + " ");
		else {
			for (int i = 0; i < cnt; i++) v.push_back("-");
			v.push_back(" ");
		}
	}

	for (auto var : v) {
		cout << var;
	}
}