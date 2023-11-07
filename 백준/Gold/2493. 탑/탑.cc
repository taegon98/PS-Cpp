#include <iostream>
#include <stack>
using namespace std;
int N, num;
stack<pair<int, int>> _s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> num;

        while (_s.size() and _s.top().second < num) {
            _s.pop();
        }

        if (_s.size()) cout << _s.top().first << " ";
        else cout << 0 << " ";
        _s.push({ i, num });
    }
}