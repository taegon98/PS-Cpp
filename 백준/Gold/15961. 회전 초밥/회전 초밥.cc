#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;
int N, d, k, c, arr[3000001], ret;
unordered_map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++) {
        mp[arr[i]]++;
    }
    ret = (int)mp.size();

    if (mp.find(c) == mp.end()) ret++;

    int l = 0, r = k - 1;

    for (int i = 1; i < N; i++) {
        int temp = 0;
        mp[arr[l]]--;
        if (!mp[arr[l]]) mp.erase(arr[l]);
        l = (l + 1) % N;

        r = (r + 1) % N;
        mp[arr[r]]++;

        if (mp.find(c) == mp.end()) temp = 1;

        ret = max(ret, (int)mp.size() + temp);
    }
    cout << ret;
}