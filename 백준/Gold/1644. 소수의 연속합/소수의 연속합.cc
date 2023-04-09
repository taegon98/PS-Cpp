#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll N, ret, tmp, idx1 = 0, idx2 = 1;
vector<ll> v;
bool is_prime[4000004] = { false };

void prime() {
	for (int i = 2; i * i <= N; i++) {
		if (!is_prime[i]) {
			for (int j = i * i; j <= N; j += i) is_prime[j] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	prime();

	for (int i = 2; i <= N; i++) {
		if (!is_prime[i]) {
			if (v.size()) tmp = i + v.back();
			else tmp = i;
			if (tmp == N) ret++;
			v.push_back(tmp);
		}
	}

	while (1) {
		if (idx2 >= v.size() or idx1 >= idx2) break;
		ll tot = v[idx2] - v[idx1];
		if (tot == N) {
			ret++;
			idx1++; idx2++;
		}
		else if (tot < N) idx2++;
		else if (tot > N) idx1++;
	}
	cout << ret;
}