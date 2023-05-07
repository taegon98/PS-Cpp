#include <iostream>
using namespace std;
typedef long long ll;
ll N, dp[34][34];

ll go(int w, int h) {
	if (w == 0 and h == 0) return 1;
	if (dp[w][h]) return dp[w][h];	//기저사례

	if (w) dp[w][h] += go(w - 1, h + 1);
	if (h) dp[w][h] += go(w, h - 1);	//로직
	return dp[w][h];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> N;
		if (!N) break;
		cout << go(N, 0) << "\n";
	}
}