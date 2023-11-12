#include <iostream>
#include <vector>
using namespace std;
int n, k, cnt;
void go(int tot, vector<int> v) {
	if (tot > n) return;
	if (tot == n) {
		cnt++;
		if (cnt == k) {
			for (int i = 0; i < v.size() - 1; i++) {
				cout << v[i] << "+";
			}
			cout << v[v.size() - 1];
			exit(0);
		}
		return;
	}

	for (int i = 1; i <= 3; i++) {
		v.push_back(i);
		go(tot + i, v);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> v;
	cin >> n >> k;

	go(0, v);
	cout << -1;
}