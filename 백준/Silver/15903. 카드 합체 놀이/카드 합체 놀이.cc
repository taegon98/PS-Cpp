#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
ll n, m, temp, ret;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        pq.push(temp);
    }

    for (int i = 0; i < m; i++) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();

        temp = a + b;

        pq.push(temp); pq.push(temp);
    }

    while (pq.size()) {
        ret += pq.top();
        pq.pop();
    }
    cout << ret;
}