#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    int tc = 1;

    while (cin >> s) {
        if (s.find('-') != string::npos) exit(0);

        stack<char> _s;
        int ret = 0;

        for (int i = 0; i < s.size(); i++) {
            if (!_s.size() and s[i] == '}') {
                _s.push('{');
                ret++;
            }
            else if (_s.size() and s[i] == '}') {
                if (_s.top() == '{') _s.pop();
                else _s.push('}');
            }
            else {
                _s.push('{');
            }
        }

        cout << tc << ". " << ret + _s.size() / 2 << "\n";
        tc++;
    }
}