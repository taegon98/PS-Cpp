#include <iostream>
#include <vector>
using namespace std;
int n;
bool prime[250001] = { false };
vector<int> v;

void cal() {
	for (int i = 2; i <= 250000; i++) {
		if (prime[i]) continue;
		for (int j = i * 2; j <= 250000; j += i) {
			prime[j] = true;
		}
	}
}

int get_ans(int from, int to) {
	int cnt = 0;
	for (int i = from + 1; i <= to; i++) {
		if (!prime[i]) cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cal(); prime[1] = true;

	while (1) {
		cin >> n;
		if (!n) break;

		v.push_back(get_ans(n, n * 2));
	}

	for (auto var : v) {
		cout << var << "\n";
	}
}