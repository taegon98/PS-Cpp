#include <string>
#include <vector>
#include <iostream>
using namespace std;
int answer, num = 10, s;

void go(int n) {
    int c = num / 10;
    
    if (n <= (4 * c)) {
        answer += (n / c);
        s -= n;
    }
    else if (n == (5 * c)) {
        if ((s - n) % (num * 10) <= 4 * num) {
            answer += (n / c);
            s -= n;
        }
        else {
            answer += (10 - n / c);
            s += (num - n);
        }
    } 
    else {
        answer += (10 - n / c);
        s += (num - n);
    }
}

int solution(int storey) {
    s = storey;
    
    while(s) {
        go(s % num);
        num *= 10;
    }

    return answer;
}