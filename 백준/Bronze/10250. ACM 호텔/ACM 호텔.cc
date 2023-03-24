#include <iostream>
#include <string>
using namespace std;

int T, H, W, N;

int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> H >> W >> N;
		int cnt = 0;
		string ret = "";

		for (int i = 1; i <= W; i++) {
			for (int j = 1; j <= H; j++) {
				cnt++;
				if (cnt == N) {
					ret += to_string(j);
					if (i < 10) ret = ret + "0" + to_string(i);
					else ret += to_string(i);
				}
			}
		}
		cout << ret << "\n";
	}
	
}