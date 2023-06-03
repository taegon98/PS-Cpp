#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
bool cmp(ll &a, ll &b) { return a > b; }

long long solution(long long n) {
    long long answer = 0;
    vector<ll> v;
    ll t = 1;
    while(n) {
        v.push_back(n % 10);
        n /= 10;
    }
    sort(v.begin(), v.end(), cmp);
    for (ll i = v.size() - 1; i >= 0; i--) {
        answer += (v[i] % 10 * t);
        t *= 10;
    }
    return answer;
}