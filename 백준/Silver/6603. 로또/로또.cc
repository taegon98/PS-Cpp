#include <iostream>
#include <vector>
using namespace std;
int arr[14], k;

void go(int idx, int depth, vector<int> v) {

	if (depth == 6) {
		for (auto var : v) cout << var << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < k; i++) {
		v.push_back(arr[i]);
		go(i + 1, depth + 1, v);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		cin >> k;
		if (!k) break;
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		vector<int> v;
		go(0, 0, v);
		cout << "\n";
	}
}