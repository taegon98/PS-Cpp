#include <iostream>
#include <stack>
using namespace std;
long long N, tmp, ret;
stack<pair<long long, long long>> s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		int cnt = 1;
		while (s.size() and s.top().first <= tmp) {
			ret += s.top().second;
			if (s.top().first == tmp) {
				cnt = s.top().second + 1;
			}
			else cnt = 1;
			s.pop();
		}
		if (!s.empty()) ret++;
		s.push({ tmp,cnt });
	}
	cout << ret;
}