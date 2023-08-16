#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int answer;

bool is_prime(ll n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    vector<int> v;
    while(n) {
        v.push_back(n % k);
        n /= k;
    }
    reverse(v.begin(), v.end());
    string s = "";
    for (auto var : v) {
        if (var == 0) {
            if (s.size() == 0) continue;
            else {
                if (is_prime(stoll(s))) answer++;
                s = "";
            }
        }
        else {
            s += to_string(var);
        }
    }
    
    if (s.size()) {
        if(is_prime(stoll(s))) answer++;
    }
    
    return answer;
}