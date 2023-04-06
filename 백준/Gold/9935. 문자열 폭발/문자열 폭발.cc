#include <iostream>
#include <stack>
#include <deque>
using namespace std;
string str, bomb;
stack<char> s1, s2, s3;
deque<char> ret;

int main() {
	cin >> str >> bomb;
	for (int i = 0; i < bomb.size(); i++) s2.push(bomb[i]);
	for (int i = 0; i < str.size(); i++) {
		bool ok = false;
		s1.push(str[i]);
		int cnt = 0;
		while (s1.size() and s2.size() and s1.top() == s2.top()) {
			s3.push(s1.top());
			s1.pop(); s2.pop(); cnt++;
			ok = true;
		}
		if (ok and cnt != bomb.size()) {
			while (s3.size()) {
				s1.push(s3.top());
				s2.push(s3.top());
				s3.pop();
			}
		}
		else {
			while (s3.size()) {
				s2.push(s3.top()); s3.pop();
			}
		}
	}
	if (!s1.size()) cout << "FRULA";
	else {
		while (s1.size()) {
			ret.push_front(s1.top()); s1.pop();
		}
		for (char ch : ret) cout << ch;
	}
}