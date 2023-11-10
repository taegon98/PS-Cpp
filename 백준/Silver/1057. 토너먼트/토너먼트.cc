#include <iostream>
#include <queue>
using namespace std;
int N, n1, n2, temp, ret;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> n1 >> n2;

	for (int i = 1; i <= N; i++) q.push(i);

	while (1) {
		ret++;
		int _size = q.size() / 2;
		queue<int> temp_q;

		for (int i = 0; i < _size; i++) {
			int a = q.front(); q.pop();
			int b = q.front(); q.pop();

			if ((a == n1 and b == n2) or (a == n2 and b == n1)) {
				cout << ret;
				exit(0);
			}
			if (a == n1 or a == n2) {
				temp_q.push(a);
			}
			else if (b == n1 or b == n2) {
				temp_q.push(b);
			}
			else temp_q.push(a);
		}
		
		if (q.size()) {
			temp_q.push(q.front());
			q.pop();
		}

		q = temp_q;
		if (temp_q.size() == 1) {
			cout << -1;
			exit(0);
		}
	}
}