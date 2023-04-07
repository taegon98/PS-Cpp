#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
typedef long long ll;
ll n, m, r, c, w;
vector<vector<ll>> v(104, vector<ll>(104));

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) v[i][j] = 0;
			else v[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> r >> c >> w;
		if (!v[r][c]) v[r][c] = w;
		else v[r][c] = min(v[r][c], w);
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (v[i][j] == INF) cout << 0 << " ";
			else cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}