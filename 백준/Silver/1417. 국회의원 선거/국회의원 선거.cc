#include <iostream>
#include <queue>
using namespace std;
int N, target, temp, ret;
priority_queue<int, vector<int>, less<int>> pq;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> target;

	for (int i = 0; i < N - 1; i++) {
		cin >> temp;
		pq.push(temp);
	}

	while (pq.size() and target <= pq.top()) {
		temp = pq.top();
		temp--;
		pq.pop();
		pq.push(temp);
		target++;
		ret++;
	}
	cout << ret;
}