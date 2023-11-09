#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;
int T, N, arr[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        int ret = -987654321;
        deque<int> dq;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + N);

        dq.push_back(arr[N - 1]);

        for (int i = N - 2; i >= 0; i--) {
            dq.push_back(arr[i]);
            i--;
            if (i >= 0) dq.push_front(arr[i]);
        }

        int l = N - 1, r = 0;
        for (int i = 0; i < N; i++) {
            ret = max(ret, abs(dq[l] - dq[r]));
            l = (l + 1) % N; r++;
        }
        cout << ret << "\n";
    }
}