#include <iostream>
#include <map>
#include <queue>
using namespace std;
int a, b, c, d;
map<pair<int, int>, int> _map;
queue<pair<int, int>> q;

void bfs(int p1, int p2) {
	q.push({ p1,p2 });
	_map[{p1, p2}] = 0;
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		if (y == c && x == d) {
			cout << _map[{y, x}];
			exit(0);
		}
		
		for (int i = 1; i <= 6; i++) {
			int ny, nx;
			if (i == 1) ny = a, nx = x;
			else if (i == 2)  ny = y, nx = b;
			else if (i == 3) ny = 0, nx = x;
			else if (i == 4) ny = y, nx = 0;
			else if (i == 5) {
				nx = x + y;
				if (nx > b) {
					ny = nx - b;
					nx = b;
				}
				else ny = 0;
			}
			else if (i == 6) {
				ny = x + y;
				if (ny > a) {
					nx = ny - a;
					ny = a;
				}
				else nx = 0;
			}
			if (ny < 0 or nx < 0 or ny > a or nx > b or
				_map.find({ ny,nx }) != _map.end()) continue;
			_map[{ny, nx}] = _map[{y, x}] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);
	cin >> a >> b >> c >> d;
	bfs(0, 0);
	cout << -1;
}