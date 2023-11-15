#include <iostream>
using namespace std;
int N, K, B, ret = 987654321, temp, bsum[100001];
bool is_break[100001] = { false };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K >> B;

	for (int i = 1; i <= B; i++) {
		cin >> temp;
		is_break[temp] = true;
	}
	for (int i = 1; i <= N; i++) {
		if (is_break[i]) {
			bsum[i] = bsum[i - 1] + 1;
		}
		else bsum[i] = bsum[i - 1];
	}
	
	int l = 0, r = K;
	while (r <= N) {
		ret = min(ret, bsum[r] - bsum[l]);
		l++; r++;
	}
	cout << ret;
}