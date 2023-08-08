#include <string>
#include <vector>
using namespace std;
int arr[100001];
int fib(int n) {
    if (n == 0) return 0;
    if (arr[n]) return arr[n];
    
    return arr[n] = (fib(n - 2) + fib(n - 1)) % 1234567;
}

int solution(int n) {
    arr[0] = 0;
    arr[1] = 1;
    int answer = fib(n) % 1234567;
    return answer;
}