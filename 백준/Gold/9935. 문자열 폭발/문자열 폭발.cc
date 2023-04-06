#include <iostream>
#include <stack>
#include <algorithm>
#include <deque>
using namespace std;
string str, bomb;
stack<char> s;
deque<char> ret;

int main() {
	cin >> str >> bomb;

	for (int i = 0; i < str.size(); i++) {
		bool ok = false;
		s.push(str[i]);
		if (s.size() >= bomb.size() and s.top() == bomb[bomb.size() - 1]) {
			string tmp = "";
			for (int i = 0; i < bomb.size(); i++) {
				tmp += s.top(); s.pop();
			}
			reverse(tmp.begin(), tmp.end());
			if (tmp != bomb) {
				for (int i = 0; i < bomb.size(); i++) s.push(tmp[i]);
			}
		}
	}
	if (!s.size()) cout << "FRULA";
	else {
		while (s.size()) {
			ret.push_front(s.top()); s.pop();
		}
		for (char ch : ret) cout << ch;
	}
}