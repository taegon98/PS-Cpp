#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int end = 0, t = 1;
    bool ok;
    
    if (s[0] == '-') ok = false, end = 1;
    else if (s[0] == '+') ok = true, end = 1;

    for (int i = s.size() - 1; i >= end; i--) {
        answer += ((s[i] - '0') * t);
        t *= 10;
    }
    if (!ok) answer *= -1;
    return answer;
}