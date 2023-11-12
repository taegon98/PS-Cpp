#include <iostream>
#include <cstring>
using namespace std;
int n, m, option, a, b, parent[1000001];

int Find(int n) {
	if (parent[n] == -1) return n;
	else return parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(parent, -1, sizeof(parent));
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> option >> a >> b;

		int temp1 = Find(a);
		int temp2 = Find(b);

		if (!option and temp1 != temp2) {
			Union(temp1, temp2);
		}
		else if (option) {
			if (temp1 == temp2) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}
}