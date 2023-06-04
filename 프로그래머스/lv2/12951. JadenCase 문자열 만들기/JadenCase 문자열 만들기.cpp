#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
         if (s[i] == ' ') {
            answer += ' ';
            flag = true;
            continue;
        }
        if (!isalpha(s[i])) {
            answer += s[i];
            flag = false;
            continue;
        }
        if (flag) {
            answer += toupper(s[i]);
            flag = false;
        }
        else if (!flag) answer += tolower(s[i]);
    }
    return answer;
}