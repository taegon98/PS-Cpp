#include <iostream>
using namespace std;
typedef long long ll;
ll N, M, arr[1000001], ret = 1000000000001;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    ll l = 0, r = 10000000000001;

    while (l <= r) {
        ll m = (l + r) / 2;
        ll cnt = 0;

        for (int i = 0; i < N; i++) {
            cnt += (m / arr[i]);
        }

        if (cnt < M) l = m + 1;
        else if (cnt >= M) {
            r = m - 1;
            ret = min(ret, m);
        }
    }
    cout << ret;
}