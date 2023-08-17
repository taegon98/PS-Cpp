#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int rem = 0;
    
    while(n >= a) {
        rem = n % a;
        n = (n / a) * b;
        answer += n;
        n += rem;
    }
    
    return answer;
}