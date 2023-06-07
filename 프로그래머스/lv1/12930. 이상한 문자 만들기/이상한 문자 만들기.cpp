#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            idx = 0;
            continue;
        }
        if (idx % 2 == 0) answer += toupper(s[i]);
        else answer += tolower(s[i]);
        idx++;
    }
    return answer;
}