#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int div = 0;
    int num = x;
    while(num) {
        div += (num % 10);
        num /= 10;
    }
    if (x % div == 0) answer = true;
    else answer = false;
    return answer;
}