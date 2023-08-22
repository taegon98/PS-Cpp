#include <string>
#include <vector>

using namespace std;
int arr[2001];
long long solution(int n) {
    long long answer = 0;
    arr[1] = 1; arr[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i-2] + arr[i-1]) % 1234567;
    }
    answer = arr[n] % 1234567;
    return answer;
}