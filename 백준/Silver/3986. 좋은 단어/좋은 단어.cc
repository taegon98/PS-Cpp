#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, cnt = 0;
	string s;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> s;
		stack<char> _stack;

		for (int idx = 0; idx < s.size(); idx++) {
			if (!_stack.empty() and _stack.top() == s[idx]) _stack.pop();
			else _stack.push(s[idx]);
		}
		if (_stack.empty()) cnt++;
	}
	cout << cnt;

	return 0;
}