#include <string>
#include <vector>
using namespace std;

int check(int n) {
    int cnt = 0;
    while(n) {
        if (n % 2 == 1) cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    vector<int> v;

    int ret = check(n++);
    
    while(1) {
        if(check(n) == ret) {
            answer = n;
            break;
        }
        n++;
    }
    return answer;
}