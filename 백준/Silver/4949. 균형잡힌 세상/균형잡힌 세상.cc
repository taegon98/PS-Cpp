#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s; getline(cin, s);
	while (s != ".") {
		stack<char> _stack;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' or s[i] == '[') _stack.push(s[i]);
			else if (s[i] == ')') {
				if (_stack.empty() or _stack.top() != '(') { _stack.push('.'); break; }
				else if (_stack.top() == '(') _stack.pop();
			}
			else if (s[i] == ']') {
				if (_stack.empty() or _stack.top() != '[') { _stack.push('.'); break; }
				else if (_stack.top() == '[') _stack.pop();
			}
		}
		if (_stack.empty()) cout << "yes\n";
		else cout << "no\n";
		getline(cin, s);
	}
	return 0;
}