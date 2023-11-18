#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int T, n;
bool is_prime[10001] = { false };
vector<int> v;
unordered_map<int, int> mp;

void prime_check() {
    int idx = 0;
    is_prime[1] = true;
    for (int i = 2; i <= 10000; i++) {
        if (is_prime[i]) continue;
        for (int j = i * 2; j <= 10000; j += i) {
            is_prime[j] = true;
        }
    }

    for (int i = 2; i <= 10000; i++) {
        if (!is_prime[i]) {
            v.push_back(i);
            mp[i] = idx++;
        }
     }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> T;
    prime_check();

    for (int tc = 1; tc <= T; tc++) {
        cin >> n;
        int temp = n;

        while (1) {
            if (!is_prime[temp]) break;
            temp--;
        }

        int l = 0, r = mp[temp], ret_l, ret_r;

        while (l <= r) {
            if (v[l] + v[r] > n) {
                r--;
            }
            else if (v[l] + v[r] < n) {
                l++;
            }
            else if (v[l] + v[r] == n) {
                ret_l = l, ret_r = r;
                l++;
            }
        }

        cout << v[ret_l] << " " << v[ret_r] << "\n";
    }
}