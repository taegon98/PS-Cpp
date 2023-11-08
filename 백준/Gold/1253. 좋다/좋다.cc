#include <iostream>
#include <algorithm>
using namespace std;
int N, arr1[2001], arr2[2001], ret;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    sort(arr2, arr2 + N);

    for (int i = 0; i < N; i++) {
        bool flag = true;
        int l = 0, r = N - 1;

        while (l < r) {
            if (arr2[l] == arr1[i] and flag) {
                flag = false; l++;
                continue;
            }
            else if (arr2[r] == arr1[i] and flag) {
                flag = false;  r--;
                continue;
            }

            int temp = arr2[l] + arr2[r];
            if (temp == arr1[i]) {
                ret++;
                break;
            }
            else if (temp < arr1[i]) l++;
            else if (temp > arr1[i]) r--;
        }
    }
    cout << ret;
}