#include <iostream>
using namespace std;
long long A, B, ret = 10987654321;

void go(long long depth, long long num) {
	if (num > B) return;
	if (num == B) {
		ret = min(ret, depth);
		return;
	}
	go(depth + 1, num * 2);
	go(depth + 1, num * 10 + 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B;
	go(0, A);
	if (ret == 10987654321) cout << -1;
	else cout << ret + 1;
}