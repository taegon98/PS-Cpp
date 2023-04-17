#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, num, tmp, max_value = -987654321, min_value = 9877654321;
vector<int> v(14);
vector<int> op;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	for (int i = 0; i < 4; i++) {
		cin >> num;
		for (int i = 0; i < num; i++) op.push_back(tmp);
		tmp++;
	}
	do {
		int ret = v[0], idx = 1;
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 0) ret += v[idx];
			else if (op[i] == 1) ret -= v[idx];
			else if (op[i] == 2) ret *= v[idx];
			else if (op[i] == 3) ret /= v[idx];
			idx++;
		}
		max_value = max(max_value, ret);
		min_value = min(min_value, ret);
	} while (next_permutation(op.begin(), op.end()));
	cout << max_value << "\n" << min_value;
}