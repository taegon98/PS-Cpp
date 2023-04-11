#include <iostream>
#include <queue>
using namespace std;
int N, K, on, ret, num[104], socket[104];
queue<int> q[104];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		cin >> num[i];
		q[num[i]].push(i);
	}
	for (int i = 1; i <= K; i++) {
		bool ok = false;
		for (int j = 0; j < on; j++) {
			if (socket[j] == num[i]) { ok = true; break; }
		}
		if (ok) {
			q[num[i]].pop(); continue;
		}
		else if (on < N) {
			socket[on++] = num[i];
			q[num[i]].pop();
		}
		else {
			if (q[socket[0]].empty()) {
				socket[0] = num[i];
				q[num[i]].pop(); ret++;
				continue;
			}
			int m = q[socket[0]].front();
			int idx = 0;
			for (int j = 1; j < on; j++) {
				if (q[socket[j]].empty()) {
					idx = j;
					break;
				}
				else if (m < q[socket[j]].front()) {
					m = q[socket[j]].front();
					idx = j;
				}
			}
			socket[idx] = num[i];
			q[num[i]].pop();
			ret++;
		}
	}
	cout << ret;
}