#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int rem = 0;
    
    while(n >= a) {
        int temp = (n / a) * b;
        rem = n % a;
        answer += temp;
        temp += rem;
        n = temp;
    }
    
    return answer;
}