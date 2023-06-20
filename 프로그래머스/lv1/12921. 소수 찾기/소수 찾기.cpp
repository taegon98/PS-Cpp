#include <string>
#include <vector>

using namespace std;
bool is_prime[1000001];
int ret;

void go(int n) {
    for (int i = 2; i <= n; i++) {
        for (int j = i + i; j <= n ;j += i) {
            is_prime[j] = true;
        }
    }
    for (int i = 2; i <= n; i++) 
        if (!is_prime[i]) ret++;
}

int solution(int n) {
    int answer = 0;
    go(n);
    answer = ret;
    return answer;
}