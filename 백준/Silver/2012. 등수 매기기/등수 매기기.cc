#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll N, temp, ret, arr[500001];
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	v.push_back(0);
	sort(v.begin(), v.end());
	for (int i = 1; i <= N; i++) {
		if (v[i] == i) continue;
		else ret += abs(v[i] - i);
	}
	cout << ret;
}