#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int A = a < b ? a : b;
    int B = a < b ? b : a;
    for (int i = A; i <= B; i++) {
        answer += i;
    }
    return answer;
}