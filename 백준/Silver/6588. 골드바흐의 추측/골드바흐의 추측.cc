#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
bool prime[1000001] = { false };
vector<int> v;
map<int, int> mp;

void cal() {
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i]) continue;
		for (int j = i * 2; j <= 1000000; j += i) {
			prime[j] = true;
		}
	}
	int idx = 0;
	for (int i = 2; i <= 1000000; i++) {
		if (!prime[i] and i % 2 == 1) {
			v.push_back(i);
			mp[i] = idx++;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	prime[1] = true; cal();

	while (1) {
		cin >> n;
		if (!n) break;
		int temp = n, l = 0, r;
		temp--;

		while (1) {
			if (!prime[temp]) {
				r = mp[temp];
				break;
			}
			temp--;
		}
		
		while (1) {
			if (l > r) {
				cout << "Goldbach's conjecture is wrong." << "\n";
				break;
			}

			temp = v[l] + v[r];
			if (temp == n) {
				cout << n << " = " << v[l] << " + " << v[r] << "\n";
				break;
			}
			else if (temp > n) r--;
			else if (temp < n) l++;
		}
	}
}