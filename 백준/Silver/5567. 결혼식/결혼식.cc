#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> v[501];
set<int> _set;
int n, m, s, e, visited[501];

void go(int depth, int cur) {

    _set.insert(cur);
    if (depth == 2) return;

    for (auto var : v[cur]) {
        if (visited[var]) continue;
        visited[var] = 1;
        go(depth + 1, var);
        visited[var] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }
    visited[1] = 1;
    go(0, 1);
    cout << _set.size() - 1;
}