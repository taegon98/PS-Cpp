#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, s, e, ret, visited[20001];
bool flag = false;
vector<int> v[20001];

void go(int depth, int cur) {
    queue<int> q;
    q.push(cur);
    visited[cur] = 1;

    while (q.size()) {
        int n = q.front(); q.pop();

        for (auto var : v[n]) {
            if (visited[var]) continue;
            visited[var] = visited[n] + 1;
            ret = max(ret, visited[var]);
            q.push(var);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int pos, cnt = 1;
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    go(0, 1);

    for (int i = 1; i <= N; i++) {
        if (ret == visited[i]) {
            if (!flag) {
                flag = true;
                pos = i;
            }
            else cnt++;
        }
    }

    cout << pos << " " << ret - 1 << " " << cnt;
}