#include <iostream>
#include <deque>
using namespace std;
int N, M, idx, ret;
deque<int>dq;

int check(int n) {
	for (int i = 0; i < dq.size(); i++) {
		if (n == dq[i]) return i;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) dq.push_back(i);

	for (int i = 0; i < M; i++) {
		cin >> idx;
		
		if (dq.front() == idx) dq.pop_front();
		else {
			while (1) {
				ret++;
				int pos = check(idx);
				if (dq.size() / 2 >= pos) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
				else {
					dq.push_front(dq.back());
					dq.pop_back();
				}
				if (dq.front() == idx) {
					dq.pop_front();
					break;
				}
			}
		}
	}
	cout << ret;
}