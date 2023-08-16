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

void condition1(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) continue;
        ll temp = 0, digit = 1;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j]) continue;
            for (int k = j - 1; k > i; k--) {
                temp += (v[k] * digit);
                digit *= 10;
            }
            if (is_prime(temp)) answer++;
            break;
        }
    }
}

void condition2(vector<int> v) {
    ll temp = 0, digit = 1;
    for (int i = 0; i < v.size(); i++) {
        if (!v[i]) {
            for (int j = i - 1; j >= 0; j--) {
                temp += (v[j] * digit);
                digit *= 10;
            }
            if (is_prime(temp)) answer++;
            return;
        }
    }
    return;
}

void condition3(vector<int> v) {
    ll temp = 0, digit = 1;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (!v[i]) {
            for (int j = v.size() - 1; j > i; j--) {
                temp += (v[j] * digit);
                digit *= 10;
            }
            if (is_prime(temp)) answer++;
            return;
        }
    }
    return;
}

void condition4(vector<int> v) {
    ll temp = 0, digit = 1;
    for (int i = v.size() - 1; i >= 0; i--) {
        temp += (v[i] * digit);
        digit *= 10;
    }
    if (is_prime(temp)) answer++;
    return;
}

int solution(int n, int k) {
    vector<int> v;
    bool flag = true;
    while(n) {
        v.push_back(n % k);
        n /= k;
    }
    reverse(v.begin(), v.end());
    
    condition1(v);
    condition2(v);
    condition3(v);
    for (int i = 0; i < v.size(); i++) {
        if (!v[i]) {
            flag = false;
            break;
        }
    }
    if (flag) condition4(v);
    return answer;
}