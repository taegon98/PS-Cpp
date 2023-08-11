#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, psum[10001], l, r = 1;
int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + i;
    }
    
    while(l <= r and r <= n) {
        if (psum[r] - psum[l] < n) r++;
        else if (psum[r] - psum[l] >= n) {
            if (psum[r] - psum[l] == n) answer++;
            l++;
        }
    }
    return answer;
}