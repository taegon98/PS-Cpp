#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
int N, M, from, to, visited[101];
unordered_map<int, int> l, s;

void go(int pos) {
	queue<int> q;
	q.push(pos);
	visited[pos] = 1;

	while (q.size()) {
		int pos = q.front();
		q.pop();

		if (pos == 100) {
			cout << visited[pos] - 1;
			exit(0);
		}

		for (int i = 1; i <= 6; i++) {
			int npos = pos + i;

			if (l.find(npos) != l.end()) {
				npos = l[npos];
			}
			if (s.find(npos) != s.end()) {
				npos = s[npos];
			}
			if (visited[npos]) continue;
			if (npos > 100) continue;
			q.push(npos);
			visited[npos] = visited[pos] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> from >> to;
		l[from] = to;
	}

	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		s[from] = to;
	}

	go(1);
}