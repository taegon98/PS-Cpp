#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0, pre = 0;
    
    while(dartResult.size()) {
        int i = 1, idx = 1, num, temp = 0;
        for (; i < dartResult.size(); i++) {
            if (dartResult[i] == '0' and i == 1) continue;
            if (dartResult[i] != 'S' and dartResult[i] != 'D' and dartResult[i] != 'T'
               and dartResult[i] != '*' and dartResult[i] != '#') break;
        }
        string s = dartResult.substr(0, i);
        dartResult.erase(0, i);

        if (s[idx] == '0') {
            idx++; num = 10;
        }
        else num = s[0] - '0';
        
        if (s[idx] == 'S') temp = num;
        else if (s[idx] == 'D') temp = pow(num, 2);
        else if (s[idx] == 'T') temp = pow(num, 3);
        idx++;
        
        if ((num == 10 and s.size() == 4) or (num != 10 and s.size() == 3)) {
            if (s[idx] == '*') {
                temp *= 2;
                answer += pre;
            }
            else if (s[idx] == '#') temp *= -1;
        }
        pre = temp;
        answer += temp;
    }
    
    return answer;
}