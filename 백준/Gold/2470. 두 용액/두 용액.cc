#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, arr[100001], l = 1, r, ret = 2000000001, ret_l, ret_r;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    r = N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr + 1, arr + N + 1);

    while (l < r) {
        int temp = arr[l] + arr[r];
        
        if (abs(temp) < ret) {
            ret_l = arr[l];
            ret_r = arr[r];
            ret = abs(temp);
        }

        if (temp <= 0) l++;
        else r--;
    }
    cout << ret_l << " " << ret_r;
}