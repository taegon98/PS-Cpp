#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D, visited[1000001];
queue<int> q;

void go(int cur) {
	while (q.size()) {
		int temp = q.front();
		q.pop();

		if (temp == G) {
			cout << visited[temp] - 1;
			exit(0);
		}

		if (temp + U <= F and !visited[temp + U]) {
			q.push(temp + U);
			visited[temp + U] = visited[temp] + 1;
		}
		if (temp - D > 0 and !visited[temp - D]) {
			q.push(temp - D);
			visited[temp - D] = visited[temp] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> F >> S >> G >> U >> D;
	q.push(S);
	visited[S] = 1;
	go(S);
	cout << "use the stairs";
}