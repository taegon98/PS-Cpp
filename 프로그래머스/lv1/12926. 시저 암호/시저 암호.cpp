#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (auto var : s) {
        if (var == ' ') {
            answer += ' ';
            continue;
        }
        int num = var + n;
        if (var >= 65 and var <= 90) {
            if (num > 90) num = 65 + (num - 91);
        }
        else if (var >= 97 and var <= 122) {
            if (num > 122) num = 97 + (num - 123);
        }
        answer += char(num);
    }
    return answer;
}