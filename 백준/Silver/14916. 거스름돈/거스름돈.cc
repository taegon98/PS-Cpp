#include <iostream>
using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int ret = 0, temp = n % 5;
    if (n < 5 and n % 2 == 1) {
        cout << -1;
        return 0;
    }
    else if (temp % 2 == 0) {
        ret += (temp / 2) + (n / 5);
    }
    else {
        temp += 5;
        ret += (temp / 2) + (n / 5) - 1;
    }
    cout << ret;
}