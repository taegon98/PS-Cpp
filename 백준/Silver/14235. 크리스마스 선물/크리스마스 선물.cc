#include <iostream>
#include <queue>
using namespace std;
int n, a, temp;
priority_queue<int, vector<int>, less<int>> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (!a) {
			if (!pq.size()) cout << -1 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			for (int j = 0; j < a; j++) {
				cin >> temp;
				pq.push(temp);
			}
		}
	}
}