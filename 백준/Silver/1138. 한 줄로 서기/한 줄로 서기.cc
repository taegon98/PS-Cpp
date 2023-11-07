#include <iostream>
using namespace std;
int N, num, arr[11];

void check(int idx, int num) {
    int i = 1, cnt = 0;
    for (; i < N; i++) {
        if (cnt == num) break;
        if (!arr[i]) cnt++;
    }

    for (int j = i; j <= N; j++) {
        if (!arr[j]) {
            arr[j] = idx;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> num;
        check(i, num);
    }

    for (int i = 1; i <= N; i++) cout << arr[i] << " ";
}