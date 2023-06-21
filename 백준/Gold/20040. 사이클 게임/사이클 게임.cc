#include <iostream>
#include <cstring>
using namespace std;
int n, m, s, e, ret, parent[500001];
bool ok = true;

int find(int num) {
	if (parent[num] == -1) return num;
	else return parent[num] = find(parent[num]);
}

void Union(int a, int b) { parent[a] = b; }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(parent, -1, sizeof(parent));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		int a = find(s);
		int b = find(e);
		if (a != b) Union(a, b);
		else if (ok and a == b) ret = i + 1, ok = false;
	}
	cout << ret;
}