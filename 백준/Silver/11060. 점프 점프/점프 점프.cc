#include <iostream>
#include <queue>
using namespace std;
int N, arr[1001], visited[1001];

int go(int pos) {
	queue<int> q;
	q.push(pos);
	visited[pos] = 1;

	while (q.size()) {
		int temp = q.front();
		int v = arr[temp];
		q.pop();

		if (temp == N) return visited[N] - 1;

		for (int i = 1; i <= v; i++) {
			if (temp + i > N) continue;
			if (!visited[temp + i]) {
				visited[temp + i] = visited[temp] + 1;
				q.push(temp + i);
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cout << go(1);
}