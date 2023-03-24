#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, diff = 987654321, ret;
int arr[104];
bool check[104] = { false };

void perm(int idx, int tot) {
	if (idx == 3) {
		if (M < tot) return;
		if (M - tot < diff) {
			diff = M - tot;
			ret = tot;
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i]) continue;
		check[i] = true;
		perm(idx + 1, tot + arr[i]);
		check[i] = false;
	}
}

int main() {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> arr[i];
	perm(0, 0);
	cout << ret;
}