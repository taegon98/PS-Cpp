#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int N, m, idx = 1;
	vector<pair<int, int>> v;
	stack<int> s;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> m;
		v.push_back(make_pair(m, -1));
	}
	s.push(0);
	for (int i = 1; i < N; i++) {
		while (!s.empty() and v[s.top()].first < v[i].first) {
			v[s.top()].second = v[i].first;
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < v.size(); i++) cout << v[i].second << " ";
}